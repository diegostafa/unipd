#include "entry_creator.h"

std::time_t entry_creator::get_current_time() const {
  return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

unsigned long int entry_creator::get_file_size(const std::string& path) const {
  return std::ifstream(path, std::ifstream::ate | std::ifstream::binary).tellg();
}

std::pair<unsigned int, unsigned int> entry_creator::get_image_dimension(const std::string& img_path) const {
  FILE* f = fopen(img_path.c_str(), "rb");
  if (f == 0)
    throw std::runtime_error("File non esistente");
  fseek(f, 0, SEEK_END);
  long len = ftell(f);
  fseek(f, 0, SEEK_SET);
  if (len < 24) {
    fclose(f);
    throw std::runtime_error("Formato del file errato");
  }
  unsigned char buf[24];
  fread(buf, 1, 24, f);

  // For JPEGs, we need to read the first 12 bytes of each chunk.
  // We'll read those 12 bytes at buf+2...buf+14, i.e. overwriting the
  // existing buf.
  if (buf[0] == 0xFF && buf[1] == 0xD8 && buf[2] == 0xFF && buf[3] == 0xE0 &&
    buf[6] == 'J' && buf[7] == 'F' && buf[8] == 'I' && buf[9] == 'F') {
    long pos = 2;
    while (buf[2] == 0xFF) {
      if (buf[3] == 0xC0 || buf[3] == 0xC1 || buf[3] == 0xC2 ||
        buf[3] == 0xC3 || buf[3] == 0xC9 || buf[3] == 0xCA ||
        buf[3] == 0xCB)
        break;
      pos += 2 + (buf[4] << 8) + buf[5];
      if (pos + 12 > len)
        break;
      fseek(f, pos, SEEK_SET);
      fread(buf + 2, 1, 12, f);
    }
  }

  fclose(f);

  // JPEG: (first two bytes of buf are first two bytes of the jpeg file; rest
  // of buf is the DCT frame
  if (buf[0] == 0xFF && buf[1] == 0xD8 && buf[2] == 0xFF) {
    return { (buf[9] << 8) + buf[10], (buf[7] << 8) + buf[8] };
  }

  // PNG: the first frame is by definition an IHDR frame, which gives
  // dimensions
  if (buf[0] == 0x89 && buf[1] == 'P' && buf[2] == 'N' && buf[3] == 'G' &&
    buf[4] == 0x0D && buf[5] == 0x0A && buf[6] == 0x1A && buf[7] == 0x0A &&
    buf[12] == 'I' && buf[13] == 'H' && buf[14] == 'D' && buf[15] == 'R') {
    return {
        (buf[16] << 24) + (buf[17] << 16) + (buf[18] << 8) + (buf[19] << 0),
            (buf[20] << 24) + (buf[21] << 16) + (buf[22] << 8) + (buf[23] << 0) };
  }

  throw std::runtime_error("File non corretto");
}

text_message* entry_creator::create_text_message(const std::string& sender, const std::string& content, unsigned int reply_id) const {
  return new text_message(sender, get_current_time(), content, reply_id);
}

location_message* entry_creator::create_location_message(const std::string& sender, float lat, float lon, unsigned int reply_id) const {
  return new location_message(sender, get_current_time(), lat, lon, reply_id);
}

contact_message* entry_creator::create_contact_message(const std::string& sender, const std::string& name, const std::string& number, unsigned int reply_id) const {
  return new contact_message(sender, get_current_time(), name, number, reply_id);
}

image_file* entry_creator::create_image_file(const std::string& sender, const std::string& path, unsigned int reply_id) const {
  auto dim = get_image_dimension(path);
  return new image_file(sender, get_current_time(), path,  get_file_size(path), dim.first, dim.second, reply_id);
}

generic_file* entry_creator::create_generic_file(const std::string& sender, const std::string& path, unsigned int reply_id) const {
  return new generic_file(sender, get_current_time(), path, get_file_size(path), reply_id);
}
