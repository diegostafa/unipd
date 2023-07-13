# 0 - STAFA - CREAZIONE REPO SU GITHUB, PROGETTO, MILESTONE, ISSUE

repo="mtss-assignment-2"
reponame="/home/diego/uni/mtss-assignment-2"

# 1 - STAFA - INIZIALIZZARE GIT FLOW


mkdir /home/diego/uni/mtss-assignment-2
cd /home/diego/uni/mtss-assignment-2
git flow init
git config credential.helper store
git remote add origin "https://github.com/diegostafa/mtss-assignment-2.git"
git push -u origin master
git push -u origin develop

# 2 - STAFA - SETUP MAVEN

git flow feature start setup-maven
mvn archetype:generate -DgroupId=it.unipd.mtss -DartifactId=e-shop-manager -DarchetypeArtifactId=maven-archetype-quickstart -DinteractiveMode=false

mv /home/diego/uni/mtss-assignment-2/e-shop-manager/* /home/diego/uni/mtss-assignment-2/
rmdir /home/diego/uni/mtss-assignment-2/e-shop-manager/

echo -e "/target" >> /home/diego/uni/mtss-assignment-2/.gitignore
echo -e ".vscode/" >> /home/diego/uni/mtss-assignment-2/.gitignore
echo -e "<project xmlns=\"http://maven.apache.org/POM/4.0.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"
  xsi:schemaLocation=\"http://maven.apache.org/POM/4.0.0 http://maven.apache.org/maven-v4_0_0.xsd\">
  <modelVersion>4.0.0</modelVersion>
  <groupId>it.unipd.mtss</groupId>
  <artifactId>e-shop-manager</artifactId>
  <packaging>jar</packaging>
  <version>1.0-SNAPSHOT</version>
  <name>e-shop-manager</name>
  <url>http://maven.apache.org</url>
  <dependencies>
    <dependency>
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.12</version>
      <scope>test</scope>
    </dependency>
  </dependencies>
  <properties>
    <maven.compiler.source>1.8</maven.compiler.source>
    <maven.compiler.target>1.8</maven.compiler.target>
  </properties>
</project>" > /home/diego/uni/mtss-assignment-2/pom.xml
git add .
git commit -m "setup maven, close #1"
git push -u origin feature/setup-maven
git flow feature finish -k setup-maven
git push -u origin develop


# 3 - CIANO - SETUP CHECKSTYLE

git clone "https://github.com/diegostafa/mtss-assignment-2.git"
cd mtss-assignment-2
git flow init
git flow feature start setup-checkstyle
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////" > /home/diego/uni/mtss-assignment-2/checkstyle.header

echo -e "<?xml version=\"1.0\"?>
<!DOCTYPE module PUBLIC \"-//Puppy Crawl//DTD Check Configuration 1.2//EN\"
\"http://www.puppycrawl.com/dtds/configuration_1_2.dtd\">

<module name=\"Checker\">
	<module name=\"TreeWalker\">

		<module name=\"BooleanExpressionComplexity\">
		  <property name=\"max\" value=\"7\"/>
		</module>

		<module name=\"CyclomaticComplexity\">
		  <property name=\"max\" value=\"30\"/>
		</module>	

		<module name=\"MethodLength\">
		  <property name=\"tokens\" value=\"METHOD_DEF\"/>
		  <property name=\"max\" value=\"160\"/>
		  <property name=\"countEmpty\" value=\"false\"/>
		</module>	

		<module name=\"AvoidStarImport\">
		  <property name=\"excludes\" value=\"java.io,java.net,java.lang.Math\"/>
		  <property name=\"allowClassImports\" value=\"false\"/>
		  <property name=\"allowStaticMemberImports\" value=\"false\"/>
		</module>

		<module name=\"EmptyCatchBlock\">
		  <property name=\"exceptionVariableName\" value=\"expected|ignore\"/>
		</module>

		<module name=\"IllegalImport\">
		  <property name=\"illegalPkgs\" value=\"java.io, java.sql\"/>
		</module>

		<module name=\"NeedBraces\">
		  <property name=\"allowSingleLineStatement\" value=\"true\"/>
		</module>

	</module>

	<module name=\"FileTabCharacter\">
		<property name=\"eachLine\" value=\"true\"/>
	</module>	

	<module name=\"FileLength\">
		<property name=\"max\" value=\"2000\"/>
	</module>


  <module name=\"RegexpHeader\">
    <property name=\"headerFile\" value=\"checkstyle.header\"/>
    <property name=\"multiLines\" value=\"2,3,4\"/>
  </module>

  <module name=\"LineLength\">
		  <property name=\"max\" value=\"160\"/>
	</module>

</module>" > /home/diego/uni/mtss-assignment-2/checkstyle.xml

echo -e "<project xmlns=\"http://maven.apache.org/POM/4.0.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"
  xsi:schemaLocation=\"http://maven.apache.org/POM/4.0.0 http://maven.apache.org/maven-v4_0_0.xsd\">
  <modelVersion>4.0.0</modelVersion>
  <groupId>it.unipd.mtss</groupId>
  <artifactId>e-shop-manager</artifactId>
  <packaging>jar</packaging>
  <version>1.0-SNAPSHOT</version>
  <name>e-shop-manager</name>
  <url>http://maven.apache.org</url>
  <dependencies>
    <dependency>
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.12</version>
      <scope>test</scope>
    </dependency>
  </dependencies>
  <properties>
    <maven.compiler.source>1.8</maven.compiler.source>
    <maven.compiler.target>1.8</maven.compiler.target>
  </properties>
  <build>
    <plugins>
      <plugin>
        <groupId>org.apache.maven.plugins</groupId>
        <artifactId>maven-checkstyle-plugin</artifactId>
        <version>3.1.2</version>
        <configuration>
        <failsOnError>true</failsOnError>
        <configLocation>checkstyle.xml</configLocation>
        <consoleOutput>true</consoleOutput>
        </configuration>
        <executions>
        <execution>
        <phase>package</phase>
        <goals>
        <goal>checkstyle</goal>
        </goals>
        </execution>
        </executions>
      </plugin>
    </plugins>
  </build>
</project>" > /home/diego/uni/mtss-assignment-2/pom.xml

echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        System.out.println( \"Hello World!\" );
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/App.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Unit test for simple App.
 */
public class AppTest 
    extends TestCase
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public AppTest( String testName )
    {
        super( testName );
    }

    /**
     * @return the suite of tests being tested
     */
    public static Test suite()
    {
        return new TestSuite( AppTest.class );
    }

    /**
     * Rigourous Test :-)
     */
    public void testApp()
    {
        assertTrue( true );
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/AppTest.java

git add .
git commit -m "setup checkstyle, close #2"
git push -u origin feature/setup-checkstyle
git flow feature finish -k setup-checkstyle
git push -u origin develop

# 4 - STAFA - SETUP CI

git pull
git flow feature start setup-ci
mkdir -p /home/diego/uni/mtss-assignment-2/.github/workflows/
echo -e "name: Build

on: [push]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v3
    - name: Set up Java and Maven
      uses: actions/setup-java@v3
      with:
        distribution: 'temurin'
        java-version: '17'
        cache: 'maven'
    - name: Build with Maven
      run: mvn -B install --file pom.xml
    - name: Upload Code Coverage in Codecov
      uses: codecov/codecov-action@v3" > /home/diego/uni/mtss-assignment-2/.github/workflows/main.yml

echo -e "<project xmlns=\"http://maven.apache.org/POM/4.0.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"
  xsi:schemaLocation=\"http://maven.apache.org/POM/4.0.0 http://maven.apache.org/maven-v4_0_0.xsd\">
  <modelVersion>4.0.0</modelVersion>
  <groupId>it.unipd.mtss</groupId>
  <artifactId>e-shop-manager</artifactId>
  <packaging>jar</packaging>
  <version>1.0-SNAPSHOT</version>
  <name>e-shop-manager</name>
  <url>http://maven.apache.org</url>
  <dependencies>
    <dependency>
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.12</version>
      <scope>test</scope>
    </dependency>
  </dependencies>
  <properties>
    <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
	  <project.reporting.outputEncoding>UTF-8</project.reporting.outputEncoding>
    <maven.compiler.source>1.8</maven.compiler.source>
    <maven.compiler.target>1.8</maven.compiler.target>
  </properties>
  <build>
    <plugins>
      <plugin>
        <groupId>org.apache.maven.plugins</groupId>
        <artifactId>maven-checkstyle-plugin</artifactId>
        <version>3.1.2</version>
        <configuration>
        <failsOnError>true</failsOnError>
        <configLocation>checkstyle.xml</configLocation>
        <consoleOutput>true</consoleOutput>
        </configuration>
        <executions>
        <execution>
        <phase>package</phase>
        <goals>
        <goal>checkstyle</goal>
        </goals>
        </execution>
        </executions>
      </plugin>
            <plugin>
        <groupId>org.jacoco</groupId>
        <artifactId>jacoco-maven-plugin</artifactId>
        <version>0.8.7</version>
        <executions>
          <execution>
            <goals>
              <goal>prepare-agent</goal>
            </goals>
          </execution>
          <execution>
            <id>report</id>
            <phase>test</phase>
            <goals>
              <goal>report</goal>
            </goals>
          </execution>
        </executions>
      </plugin>
    </plugins>
  </build>
  <reporting>
    <plugins>
      <plugin>
        <groupId>org.jacoco</groupId>
        <artifactId>jacoco-maven-plugin</artifactId>
        <reportSets>
          <reportSet>
            <reports>
              <!-- select non-aggregate reports -->
              <report>report</report>
            </reports>
          </reportSet>
        </reportSets>
      </plugin>
    </plugins>
  </reporting>
</project>" > /home/diego/uni/mtss-assignment-2/pom.xml
echo -e "![Build](https://github.com/diegostafa/mtss-assignment-2/actions/workflows/main.yml/badge.svg)
[![codecov](https://codecov.io/github/diegostafa/mtss-assignment-2/coverage.svg?branch=master)](https://codecov.io/github/diegostafa/mtss-assignment-2?branch=master)" > /home/diego/uni/mtss-assignment-2/README.md


git add .
git commit -m "setup CI, close #3"
git push -u origin feature/setup-ci
git flow feature finish -k setup-ci
git push -u origin develop

# 5 - CIANO - CALCOLO TOTALE

git flow feature start calcolo-totale
mkdir -p /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/model
mkdir -p /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business
mkdir -p /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/exception
mkdir -p /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/model
mkdir -p /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business

rm /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/App.java
rm /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/AppTest.java

echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import java.util.List;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

public interface Bill {
    double getOrderPrice(List<EItem> orderedItems, User user)
        throws BillException;
    
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/Bill.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;
import java.util.List;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        
        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();   
        }
        
        return total;
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business.exception;

public class BillException extends RuntimeException{
    private static final long serialVersionUID = 1L;

    public BillException(String msg) {
        super(msg);
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/exception/BillException.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.model;

public class EItem {
    ItemType itemType;
    String name;
    double price;

    public EItem(ItemType itemType, String name, double price){
        if(itemType == null){
            throw new IllegalArgumentException(\"Item type is null\");
        }
        if(name == null){
            throw new IllegalArgumentException(\"Item name is null\");
        }
        if(price <= 0){
            throw new IllegalArgumentException(\"Price is less than zero\");
        }
        this.itemType = itemType;
        this.name = name;
        this.price = price;
    }

    public double getPrice(){
        return price;
    }

    public ItemType getType(){
        return itemType;
    }

    public String getName(){
        return name;
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/model/EItem.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.model;

public enum ItemType {
    Processor,
    Motherboard, 
    Mouse, 
    Keyboard
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/model/ItemType.java

echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.BillImpl;
import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {
    
    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private User user; 
    
    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 60.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 30.00));
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 45.00));
        
        assertEquals(245, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }
    
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.model;

import static org.junit.Assert.assertEquals;

import org.junit.Before;
import org.junit.Test;

public class EItemTest {

    private EItem Processor;
    private EItem Motherboard;
    private EItem Mouse;
    private EItem Keyboard;

    @Before
    public void setup() {
        Processor = new EItem( ItemType.Processor, \"Ryzen 7\",110.00);
        Motherboard = new EItem(ItemType.Motherboard, \"Asus B550\", 60.00);
        Mouse = new EItem( ItemType.Mouse, \"MX Master 3\", 30.00);
        Keyboard = new EItem( ItemType.Keyboard, \"MX Keys\", 45.00);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testTipologiaElementoNullo() {
        new EItem(null, \"Ryzen 7\", 110.00);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testnameElementoNullo() {
        new EItem(ItemType.Processor, null, 110);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testPrezzoElementoNegativo() {
        new EItem(ItemType.Processor, \"Ryzen 7\", -3.00);
    }

    @Test
    public void testGetName() {
        assertEquals(\"Ryzen 7\", Processor.getName());
        assertEquals(\"Asus B550\", Motherboard.getName());
        assertEquals(\"MX Master 3\", Mouse.getName());
        assertEquals(\"MX Keys\", Keyboard.getName());
    }

    @Test
    public void testGetPrice() {
        assertEquals(110.00, Processor.getPrice(), 0.0);
        assertEquals(60.00, Motherboard.getPrice(), 0.0);
        assertEquals(30.00, Mouse.getPrice(), 0.0);
        assertEquals(45.00, Keyboard.getPrice(), 0.0);
    }

    @Test
    public void testGetType() {
        assertEquals(ItemType.Processor, Processor.getType());
        assertEquals(ItemType.Motherboard, Motherboard.getType());
        assertEquals(ItemType.Mouse, Mouse.getType());
        assertEquals(ItemType.Keyboard, Keyboard.getType());
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/model/EItemTest.java

echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.model;

import java.time.LocalDate;

public class User {
    String username, name, lastName;
    LocalDate birthDate;

    public User(String username, 
            String name, 
            String lastName, 
            LocalDate birthDate) {
        if(username == null) {
            throw new IllegalArgumentException(\"Username is null\");
        }
        if(name == null) {
            throw new IllegalArgumentException(\"Name is null\");
        }
        if(lastName == null) {
            throw new IllegalArgumentException(\"Last name is null\");
        }
        if(birthDate == null) {
            throw new IllegalArgumentException(\"Birth date is null\");
        }
        this.username = username;
        this.name = name;
        this.lastName = lastName;
        this.birthDate = birthDate;
    }
    
    public String getUsername(){
        return username;
    }
    
    public String getName() {
        return name;
    }
    
    public String getSurname() {
        return lastName;
    }
    
    public int getAge() {
        return LocalDate.now().getYear()-birthDate.getYear();
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/model/User.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.model;

import static org.junit.Assert.assertEquals;

import java.time.LocalDate;
import org.junit.Test;

public class UserTest {

    private User diego = new User(\"diegostafa\", \"DIEGO\", \"STAFA\", LocalDate.of(2000, 8, 11));

    @Test(expected = IllegalArgumentException.class)
    public void testUsernameIsNull() {
        new User(null,\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testNameIsNull() {
        new User(\"diegostafa\",null,\"STAFA\",LocalDate.of(2000, 8, 11));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testLastNameIsNull() {
        new User(\"diegostafa\",\"DIEGO\",null,LocalDate.of(2000, 8, 11));
    }
    
    @Test(expected = IllegalArgumentException.class)
    public void testDateIsNull() {
        new User(\"diegostafa\",\"DIEGO\",\"STAFA\",null);
    }

    @Test
    public void testGetAge() {
        assertEquals(diego.getAge(), 22);
    }

    @Test
    public void testGetName() {
        assertEquals(diego.getName(), \"DIEGO\");
    }

    @Test
    public void testGetSurname() {
        assertEquals(diego.getSurname(), \"STAFA\");
    }

    @Test
    public void testGetUsername() {
        assertEquals(diego.getUsername(), \"diegostafa\");
    }
}
" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/model/UserTest.java
git add .
git commit -m "calcolo del totale, close #4"
git push -u origin feature/calcolo-totale
git flow feature finish -k calcolo-totale
git push -u origin develop


# 6 - STAFA - SCONTO PROCESSORI

git pull
git flow feature start sconto-processori
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.User;
import java.util.List;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        int processors = 0;
        EItem cheapestProcessor = null;
        
        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();
            if (item.getType() == ItemType.Processor) {
                processors++;

                if (cheapestProcessor == null) {
                    cheapestProcessor = item;
                } else if(cheapestProcessor.getPrice() > item.getPrice()) {cheapestProcessor = item;}
            }
        }

        if (processors > 5) {
            total -= cheapestProcessor.getPrice() * 0.5;
        }
        
        return total;
    }
}
" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.BillImpl;
import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {
    
    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private User user; 
    
    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 60.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 30.00));
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 45.00));
        
        assertEquals(245, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanFiveProcessors() {
        
        for(int i=0; i<6; i++) {
            orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        }       
        assertEquals(605.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
git add .
git commit -m "sconto processori, close #5"
git push -u origin feature/sconto-processori
git flow feature finish -k sconto-processori
git push -u origin develop

# 7 - CIANO - REGALO MOUSE

git flow feature start regalo-mouse
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.User;
import java.util.List;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        int processors = 0;
        int mouse = 0;

        EItem cheapestProcessor = null;
        EItem cheapestMouse=null; 
        
        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();
            if (item.getType() == ItemType.Processor) {
                processors++;

                if (cheapestProcessor == null) {
                    cheapestProcessor = item;
                } else if(cheapestProcessor.getPrice() > item.getPrice()) {cheapestProcessor = item;}
            }

            if (item.getType() == ItemType.Mouse) {
                mouse++;

                if (cheapestMouse == null) {
                    cheapestMouse = item;
                } else if(cheapestMouse.getPrice() > item.getPrice()) {cheapestMouse = item;}
            }
        }

        if (processors > 5) {
            total -= cheapestProcessor.getPrice() * 0.5;
        }
        
        if (mouse > 10) {
            total -= cheapestMouse.getPrice() * 1;
        }
        return total;
    }
}
" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.BillImpl;
import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {
    
    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private User user; 
    
    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 60.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 30.00));
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 45.00));
        
        assertEquals(245, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanFiveProcessors() {
        
        for(int i=0; i<6; i++) {
            orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        }       
        assertEquals(605.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanTenMice() {
        
        for(int i=0; i<11; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        assertEquals(300.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
git add .
git commit -m "regalo mouse, close #6"
git push -u origin feature/regalo-mouse
git flow feature finish -k regalo-mouse
git push -u origin develop

# 8 - STAFA - SCONTO MOUSE E TASTIERE

git pull
git flow feature start sconto-mouse-tastiere
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.User;
import java.util.List;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        int processors = 0;
        int mouse = 0;
        int keyboards = 0;

        EItem cheapestProcessor = null;
        EItem cheapestMouse=null; 
        EItem cheapestKeyboard = null;
        EItem cheapestMouseOrKeyboard = null;

        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();
            if (item.getType() == ItemType.Processor) {
                processors++;

                if (cheapestProcessor == null) {
                    cheapestProcessor = item;
                } else if(cheapestProcessor.getPrice() > item.getPrice()) {cheapestProcessor = item;}
            }

            if (item.getType() == ItemType.Mouse) {
                mouse++;

                if (cheapestMouse == null) {
                    cheapestMouse = item;
                } else if(cheapestMouse.getPrice() > item.getPrice()) {cheapestMouse = item;}
            }

            if (item.getType() == ItemType.Keyboard) {
                keyboards++;

                if (cheapestKeyboard == null) {
                    cheapestKeyboard = item;
                } else if(cheapestKeyboard.getPrice() > item.getPrice()) {cheapestKeyboard = item;}
            }

            if (item.getType() == ItemType.Keyboard || item.getType() == ItemType.Mouse){
                if ((cheapestMouseOrKeyboard == null) || (cheapestMouseOrKeyboard.getPrice() > item.getPrice())) {
                    cheapestMouseOrKeyboard = item;
                }
            }
        }

        if (processors > 5) {
            total -= cheapestProcessor.getPrice() * 0.5;
        }
        
        if (mouse > 10) {
            total -= cheapestMouse.getPrice() * 1;
        }

        if (keyboards == mouse && keyboards != 0) {
            total -= cheapestMouseOrKeyboard.getPrice() * 1;
        }
        return total;
    }
}
" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.BillImpl;
import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {
    
    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private User user; 
    
    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 60.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 30.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 30.00));
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 45.00));
        
        assertEquals(275, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanFiveProcessors() {
        
        for(int i=0; i<6; i++) {
            orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        }       
        assertEquals(605.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanTenMice() {
        
        for(int i=0; i<11; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        assertEquals(300.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnSameMiceAndKeyboards() {
        
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\",45.00));
        }
        assertEquals(195.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
git add .
git commit -m "sconto mouse e tastiere, close #7"
git push -u origin feature/sconto-mouse-tastiere
git flow feature finish -k sconto-mouse-tastiere
git push -u origin develop

# 9 - CIANO - SCONTO SOPRA 1000$
 
git flow feature start sconto-oltre-mille
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.User;
import java.util.List;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        int processors = 0;
        int mouse = 0;
        int keyboards = 0;

        EItem cheapestProcessor = null;
        EItem cheapestMouse=null; 
        EItem cheapestKeyboard = null;
        EItem cheapestMouseOrKeyboard = null;

        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();
            if (item.getType() == ItemType.Processor) {
                processors++;

                if (cheapestProcessor == null) {
                    cheapestProcessor = item;
                } else if(cheapestProcessor.getPrice() > item.getPrice()) {cheapestProcessor = item;}
            }

            if (item.getType() == ItemType.Mouse) {
                mouse++;

                if (cheapestMouse == null) {
                    cheapestMouse = item;
                } else if(cheapestMouse.getPrice() > item.getPrice()) {cheapestMouse = item;}
            }

            if (item.getType() == ItemType.Keyboard) {
                keyboards++;

                if (cheapestKeyboard == null) {
                    cheapestKeyboard = item;
                } else if(cheapestKeyboard.getPrice() > item.getPrice()) {cheapestKeyboard = item;}
            }


            if (item.getType() == ItemType.Keyboard || item.getType() == ItemType.Mouse){
                if ((cheapestMouseOrKeyboard == null) || (cheapestMouseOrKeyboard.getPrice() > item.getPrice())) {
                    cheapestMouseOrKeyboard = item;
                }
            }
        }

        if (processors > 5) {
            total -= cheapestProcessor.getPrice() * 0.5;
        }
        
        if (mouse > 10) {
            total -= cheapestMouse.getPrice() * 1;
        }

        if (keyboards == mouse && keyboards != 0) {
            total -= cheapestMouseOrKeyboard.getPrice() * 1;
        }

        if(total > 1000){
            total -= total * 0.1;
        }     
        return total;
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.BillImpl;
import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {
    
    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private User user; 
    
    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",100.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 100.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 100.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 100.00)); 
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 100.00));
        
        assertEquals(500, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanFiveProcessors() {
        
        for(int i=0; i<6; i++) {
            orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        }       
        assertEquals(605.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanTenMice() {
        
        for(int i=0; i<11; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        assertEquals(300.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnSameMiceAndKeyboards() {
        
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\",45.00));
        }
        assertEquals(195.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnTotalPriceGreaterThan1000Euro(){
        for(int i=0; i<20; i++) {
            orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        }    
        assertEquals(1078.20, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
git add .
git commit -m "sconto importo oltre mille, close #8"
git push -u origin feature/sconto-oltre-mille
git flow feature finish -k sconto-oltre-mille
git push -u origin develop

# 10 - STAFA - ERRORE TROPPI ELEMENTI

git pull
git flow feature start errore-troppi-elementi
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.User;
import java.util.List;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        int processors = 0;
        int mouse = 0;
        int keyboards = 0;

        EItem cheapestProcessor = null;
        EItem cheapestMouse=null; 
        EItem cheapestKeyboard = null;
        EItem cheapestMouseOrKeyboard = null;

        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }

        if (orderedItems.size() > 30) {
            throw new BillException(\"Can't buy more than 30 items\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();
            if (item.getType() == ItemType.Processor) {
                processors++;

                if (cheapestProcessor == null) {
                    cheapestProcessor = item;
                } else if(cheapestProcessor.getPrice() > item.getPrice()) {cheapestProcessor = item;}
            }

            if (item.getType() == ItemType.Mouse) {
                mouse++;

                if (cheapestMouse == null) {
                    cheapestMouse = item;
                } else if(cheapestMouse.getPrice() > item.getPrice()) {cheapestMouse = item;}
            }

            if (item.getType() == ItemType.Keyboard) {
                keyboards++;

                if (cheapestKeyboard == null) {
                    cheapestKeyboard = item;
                } else if(cheapestKeyboard.getPrice() > item.getPrice()) {cheapestKeyboard = item;}
            }


            if (item.getType() == ItemType.Keyboard || item.getType() == ItemType.Mouse){
                if ((cheapestMouseOrKeyboard == null) || (cheapestMouseOrKeyboard.getPrice() > item.getPrice())) {
                    cheapestMouseOrKeyboard = item;
                }
            }
        }

        if (processors > 5) {
            total -= cheapestProcessor.getPrice() * 0.5;
        }
        
        if (mouse > 10) {
            total -= cheapestMouse.getPrice() * 1;
        }

        if (keyboards == mouse && keyboards != 0) {
            total -= cheapestMouseOrKeyboard.getPrice() * 1;
        }

        if(total > 1000){
            total -= total * 0.1;
        }     
        return total;
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.BillImpl;
import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {
    
    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private User user; 
    
    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",100.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 100.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 100.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 100.00)); 
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 100.00));
        
        assertEquals(500, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanFiveProcessors() {
        
        for(int i=0; i<6; i++) {
            orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        }       
        assertEquals(605.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanTenMice() {
        
        for(int i=0; i<11; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        assertEquals(300.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnSameMiceAndKeyboards() {
        
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\",45.00));
        }
        assertEquals(195.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnTotalPriceGreaterThan1000Euro(){
        for(int i=0; i<20; i++) {
            orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        }    
        assertEquals(1078.20, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test(expected=BillException.class)
    public void testMax30ItemsPerOrder() {
        
        for(int i=0; i<=31; i++) {
            orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        }
        
        testBill.getOrderPrice(orderedItems, user);
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
git add .
git commit -m "errore ordine con troppi elementi, close #9"
git push -u origin feature/errore-troppi-elementi
git flow feature finish -k errore-troppi-elementi
git push -u origin develop

# 11 - CIANO - COMMISSIONE MINIMA

git flow feature start commissione-minima
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.User;
import java.util.List;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        int processors = 0;
        int mouse = 0;
        int keyboards = 0;

        EItem cheapestProcessor = null;
        EItem cheapestMouse=null; 
        EItem cheapestKeyboard = null;
        EItem cheapestMouseOrKeyboard = null;

        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }

        if (orderedItems.size() > 30) {
            throw new BillException(\"Can't buy more than 30 items\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();
            if (item.getType() == ItemType.Processor) {
                processors++;

                if (cheapestProcessor == null) {
                    cheapestProcessor = item;
                } else if(cheapestProcessor.getPrice() > item.getPrice()) {cheapestProcessor = item;}
            }

            if (item.getType() == ItemType.Mouse) {
                mouse++;

                if (cheapestMouse == null) {
                    cheapestMouse = item;
                } else if(cheapestMouse.getPrice() > item.getPrice()) {cheapestMouse = item;}
            }

            if (item.getType() == ItemType.Keyboard) {
                keyboards++;

                if (cheapestKeyboard == null) {
                    cheapestKeyboard = item;
                } else if(cheapestKeyboard.getPrice() > item.getPrice()) {cheapestKeyboard = item;}
            }


            if (item.getType() == ItemType.Keyboard || item.getType() == ItemType.Mouse){
                if ((cheapestMouseOrKeyboard == null) || (cheapestMouseOrKeyboard.getPrice() > item.getPrice())) {
                    cheapestMouseOrKeyboard = item;
                }
            }
        }

        if (processors > 5) {
            total -= cheapestProcessor.getPrice() * 0.5;
        }
        
        if (mouse > 10) {
            total -= cheapestMouse.getPrice() * 1;
        }

        if (keyboards == mouse && keyboards != 0) {
            total -= cheapestMouseOrKeyboard.getPrice() * 1;
        }

        if(total > 1000){
            total -= total * 0.1;
        }     

        if(total < 10){
            total += 2;
        }
        
        return total;
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.BillImpl;
import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {
    
    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private User user; 
    
    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 60.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 5.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 30.00)); 
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 45.00));
        
        assertEquals(250, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanFiveProcessors() {
        
        for(int i=0; i<6; i++) {
            orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        }       
        assertEquals(605.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanTenMice() {
        
        for(int i=0; i<11; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        assertEquals(300.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnSameMiceAndKeyboards() {
        
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\",45.00));
        }
        assertEquals(195.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnTotalPriceGreaterThan1000Euro(){
        for(int i=0; i<20; i++) {
            orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        }    
        assertEquals(1078.20, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test(expected=BillException.class)
    public void testMax30ItemsPerOrder() {
        
        for(int i=0; i<=31; i++) {
            orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        }
        
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApply2EuroSurplusIfTotalPriceIsLessThan10Euro(){
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",5.00)); 
        assertEquals(7.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
git add .
git commit -m "commissione minima, close #10"
git push -u origin feature/commissione-minima
git flow feature finish -k commissione-minima
git push -u origin develop

# 12 - STAFA - REGALO ORDINE

git pull
git flow feature start regalo-ordine
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.Order;
import it.unipd.mtss.model.User;

import java.util.ArrayList;
import java.util.List;
import java.time.LocalTime;

public class BillImpl implements Bill{
    
    @Override
    public double getOrderPrice(List<EItem> orderedItems, User user) throws BillException {
        double total = 0;
        int processors = 0;
        int mouse = 0;
        int keyboards = 0;

        EItem cheapestProcessor = null;
        EItem cheapestMouse=null; 
        EItem cheapestKeyboard = null;
        EItem cheapestMouseOrKeyboard = null;

        if(orderedItems == null) {
            throw new BillException(\"Order list is null\");
        }

        if(orderedItems.isEmpty()) {
            throw new BillException(\"Order list is empty\");
        }

        if (orderedItems.size() > 30) {
            throw new BillException(\"Can't buy more than 30 items\");
        }
        
        for (EItem item : orderedItems) {
            total += item.getPrice();
            if (item.getType() == ItemType.Processor) {
                processors++;

                if (cheapestProcessor == null) {
                    cheapestProcessor = item;
                } else if(cheapestProcessor.getPrice() > item.getPrice()) {cheapestProcessor = item;}
            }

            if (item.getType() == ItemType.Mouse) {
                mouse++;

                if (cheapestMouse == null) {
                    cheapestMouse = item;
                } else if(cheapestMouse.getPrice() > item.getPrice()) {cheapestMouse = item;}
            }

            if (item.getType() == ItemType.Keyboard) {
                keyboards++;

                if (cheapestKeyboard == null) {
                    cheapestKeyboard = item;
                } else if(cheapestKeyboard.getPrice() > item.getPrice()) {cheapestKeyboard = item;}
            }


            if (item.getType() == ItemType.Keyboard || item.getType() == ItemType.Mouse){
                if ((cheapestMouseOrKeyboard == null) || (cheapestMouseOrKeyboard.getPrice() > item.getPrice())) {
                    cheapestMouseOrKeyboard = item;
                }
            }
        }

        if (processors > 5) {
            total -= cheapestProcessor.getPrice() * 0.5;
        }
        
        if (mouse > 10) {
            total -= cheapestMouse.getPrice() * 1;
        }

        if (keyboards == mouse && keyboards != 0) {
            total -= cheapestMouseOrKeyboard.getPrice() * 1;
        }

        if(total > 1000){
            total -= total * 0.1;
        }     

        if(total < 10){
            total += 2;
        }
        
        return total;
    }

    public List<Order> getFreeOrders(List<Order> orders) throws BillException {
        
        List<Order> freeOrders = new ArrayList<Order>();
        
        for (int i = 0; i < orders.size(); i++) {
            
            if(orders.get(i).getUser().getAge()<18 &
             orders.get(i).getOrderTime().isAfter(LocalTime.of(18,00,00,00)) &
             orders.get(i).getOrderTime().isAfter(LocalTime.of(18,00,00,00))){
                
                freeOrders.add(orders.get(i));
            }
        }

        if(freeOrders.size() > 9){
            
            for(int i=0; i<10; i++) {
              int randomIndex = (int)(freeOrders.size() * Math.random());
              if(freeOrders.get(randomIndex).getPrice() == 0) {
                  i--;
              }
              else {
              freeOrders.get(randomIndex).setPrice(0);
              }
            }
        }
        else {
            throw new BillException(\"Order quantity is not enough for the gift discount\");
        }
        
        return freeOrders;
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/business/BillImpl.java
echo -e "////////////////////////////////////////////////////////////////////
// [DIEGO] [STAFA] [1225285]
// [LUCIANO] [WU] [1224452]
////////////////////////////////////////////////////////////////////
package it.unipd.mtss.model;

import java.util.List;
import java.time.LocalTime;

public class Order {
    List<EItem> itemList; 
    User user;
    LocalTime orderTime;
    double price; 
    
    public Order(List<EItem> itemList, 
            User user,
            LocalTime orderTime,
            double price) {
        if(itemList.isEmpty()) {
            throw new IllegalArgumentException(\"Item list is empty\");
        }
        if(user == null) {
            throw new IllegalArgumentException(\"User is null\");
        }
        if(orderTime == null) {
            throw new IllegalArgumentException(\"Order time is null\");
        }
        this.itemList = itemList; 
        this.user = user;
        this.orderTime = orderTime;
        this.price = price;
    }
    
    public double getPrice() {
        return price; 
    }
    
    public LocalTime getOrderTime() {
        return orderTime;
    }
    
    public User getUser() {
        return user;
    }
    
    public List<EItem> getItemList(){
        return itemList;
    }
    
    public void setPrice(double newPrice) {
        price = newPrice;
    }
}" > /home/diego/uni/mtss-assignment-2/src/main/java/it/unipd/mtss/model/Order.java
echo -e "package it.unipd.mtss.business;

import it.unipd.mtss.business.exception.BillException;
import it.unipd.mtss.model.ItemType;
import it.unipd.mtss.model.EItem;
import it.unipd.mtss.model.Order;
import it.unipd.mtss.model.User;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class BillImplTest {

    private List<EItem> orderedItems;
    private BillImpl testBill; 
    private LocalTime orderDate;
    private User user; 

    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        testBill = new BillImpl();
        orderDate = LocalTime.of(18,30,00,00);
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
    }
    
    @Test
    public void testTotalPrice(){
        
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\", 60.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 5.00));
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\", 30.00)); 
        orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\", 45.00));
        
        assertEquals(250, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnEmptyOrderList() {
        
        testBill.getOrderPrice(orderedItems, user);
    }
    
    @Test(expected=BillException.class)
    public void testTotalPriceOnNullOrderList() {
        orderedItems = null;
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanFiveProcessors() {
        
        for(int i=0; i<6; i++) {
            orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        }       
        assertEquals(605.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }
    
    @Test
    public void testApplyDiscountOnCheapestProductIfMoreThanTenMice() {
        
        for(int i=0; i<11; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        assertEquals(300.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnSameMiceAndKeyboards() {
        
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",30.00));
        }       
        for(int i=0; i<3; i++) {
            orderedItems.add(new EItem( ItemType.Keyboard, \"MX Keys\",45.00));
        }
        assertEquals(195.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testApplyDiscountOnTotalPriceGreaterThan1000Euro(){
        for(int i=0; i<20; i++) {
            orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        }    
        assertEquals(1078.20, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test(expected=BillException.class)
    public void testMax30ItemsPerOrder() {
        
        for(int i=0; i<=31; i++) {
            orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        }
        
        testBill.getOrderPrice(orderedItems, user);
    }

    @Test
    public void testApply2EuroSurplusIfTotalPriceIsLessThan10Euro(){
        orderedItems.add(new EItem( ItemType.Mouse, \"MX Master 3\",5.00)); 
        assertEquals(7.00, testBill.getOrderPrice(orderedItems,user), 0.0);
    }

    @Test
    public void testGiftOrderToMinors() {
        
        List<Order> orders = new ArrayList<Order>();
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        orderedItems.add(new EItem( ItemType.Motherboard, \"Asus B550\",59.90));
        String[] nomi =new String[]{\"Palladio\", \"Ferro\", \"Alluminio\", \"Mercurio\",
                        \"Platino\", \"Bronzo\", \"Arsenico\", \"Argento\", \"Tungsteno\", \"Bario\", \"Berillio\"};
        User user = null;
        for (int i = 0; i < 11; i++) {
            user = new User(nomi[i]+\"_test\",nomi[i],\"prova\",LocalDate.of(2010, 5, 12));;
            orders.add(new Order(orderedItems, user,  orderDate, testBill.getOrderPrice(orderedItems, user)));
        }
        
        List<Order> freeOrders = testBill.getFreeOrders(orders);
        int numGiftedOrders = 0;

        for (Order ord : freeOrders) {
            if(ord.getPrice() == 0) {
                numGiftedOrders++;
            }
        }
        assertEquals(10,numGiftedOrders); 
    }

    @Test(expected=BillException.class)
    public void testApplyOrderDiscountIfLessThan10Orders() { 
        
        List<Order> orders = new ArrayList<Order>();
        orderedItems.add(new EItem( ItemType.Processor, \"Ryzen 7\",110.00));
        String[] nomi =new String[]{\"Palladio\", \"Ferro\", \"Tungsteno\"};
        User user = null;
        for (int i = 0; i < 3; i++) {
            user = new User(nomi[i]+\"_test\",nomi[i],\"prova\",LocalDate.of(2010, 5, 12));;
            orders.add(new Order(orderedItems, user,  orderDate, testBill.getOrderPrice(orderedItems, user)));
        }
        
        testBill.getFreeOrders(orders);
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/business/BillImplTest.java
echo -e "package it.unipd.mtss.model;

import static org.junit.Assert.assertEquals;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

import org.junit.Before;
import org.junit.Test;

public class OrderTest {
    private EItem item;
    private List<EItem> orderedItems;
    private User user;
    private LocalTime time;
    private Order order;

    @Before
    public void setup() {
        orderedItems = new ArrayList<EItem>();
        user = new User(\"diegostafa\",\"DIEGO\",\"STAFA\",LocalDate.of(2000, 8, 11));
        time = LocalTime.of(14,00);
        item = new EItem(ItemType.Processor, \"Ryzen 7\", 110.00);
        orderedItems.add(item);
        order = new Order(orderedItems, user, time, 0);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testEmptyListItem() {
        orderedItems.clear();
        new Order(orderedItems, user, time, 0);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testUsernameIsNull() {
        new Order(orderedItems, null, time, 0);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testDateIsNull() {
        new Order(orderedItems, user, null, 0);
    }

    @Test
    public void testgetItemList() {
        assertEquals(order.getItemList(), orderedItems);
    }

    @Test
    public void testGetorderTime() {
        assertEquals(order.getOrderTime(), time);
    }

    @Test
    public void testSetPriceAndGetPrice() {
        order.setPrice(14);
        assertEquals(14,order.getPrice(),0.0);
    }

    @Test
    public void testGetUser() {
        assertEquals(order.getUser(), user);
    }
}" > /home/diego/uni/mtss-assignment-2/src/test/java/it/unipd/mtss/model/OrderTest.java
git add .
git commit -m "regalo casuale a minorenni, close #11"
git push -u origin feature/regalo-ordine
git flow feature finish -k regalo-ordine
git push -u origin develop

# 13 - STAFA - RELEASE PRIMA VERSIONE

git pull
git flow release start prima-versione
git push -u origin release/prima-versione
git add .
git commit -m "release prima versione"
git flow release finish prima-versione
git push origin master
git push origin develop
git push origin --tags
