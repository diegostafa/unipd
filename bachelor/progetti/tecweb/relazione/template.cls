\NeedsTeXFormat{LaTeX2e}[1994/06/01]
\ProvidesClass{deltax-document}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions*\relax

\LoadClass{article}

\RequirePackage[margin=30mm, headsep=15mm]{geometry}
\RequirePackage[utf8]{inputenc}
\RequirePackage[italian]{babel}
\RequirePackage{graphicx}
\RequirePackage[table]{xcolor}
\RequirePackage{tabularx}
\RequirePackage[hidelinks]{hyperref}
\RequirePackage{lastpage}
\RequirePackage{csvsimple}
\RequirePackage{fancyhdr}
\RequirePackage{calc}
\RequirePackage{tikz}
\RequirePackage{titlesec}
\RequirePackage{makecell}
\RequirePackage{longtable}
\RequirePackage{float}

% document variables
\newcommand{\vartitolo}{nome documento}
\newcommand{\varemail}{tecweb.2021@gmail.com}
\newcommand{\vardescrizione}{Relazione del progetto di Tecnologie Web}
\newcommand{\varversione}{}
\newcommand{\vardata}{}
\newcommand{\varresponsabile}{}
\newcommand{\varredattori}{}
\newcommand{\varverificatori}{}
\newcommand{\varstato}{}
\newcommand{\vardestinatari}{}
\newcommand{\varuso}{}

\newcommand{\titolo}[1]{\renewcommand{\vartitolo}{#1}}
\newcommand{\email}[1]{\renewcommand{\varemail}{#1}}
\newcommand{\descrizione}[1]{\renewcommand{\vardescrizione}{#1}}
\newcommand{\versione}[1]{\renewcommand{\varversione}{#1}}
\newcommand{\data}[1]{\renewcommand{\vardata}{#1}}
\newcommand{\responsabile}[1]{\renewcommand{\varresponsabile}{#1}}
\newcommand{\redattori}[1]{\renewcommand{\varredattori}{#1}}
\newcommand{\verificatori}[1]{\renewcommand{\varverificatori}{#1}}
\newcommand{\stato}[1]{\renewcommand{\varstato}{#1}}
\newcommand{\destinatari}[1]{\renewcommand{\vardestinatari}{#1}}
\newcommand{\uso}[1]{\renewcommand{\varuso}{#1}}

\newcommand{\colorecontenuto}{\rowcolors{2}{gray!25}{white}}
\newcommand{\coloreintestazione}{\rowcolor{gray!50}}

\makeatletter
\newenvironment{tabella}[2][\@nil]{
	\def\1{#1}
	\center
	\colorecontenuto
	\ifx\1\@nnil \tabular{#2} \else \tabularx{#1}{#2} \fi
	\coloreintestazione
}{
	\ifx\1\@nnil \endtabular \else \endtabularx \fi
	\endcenter
}
\makeatother

% changelog tab
\newcommand{\changelog}[1]{
	\colorecontenuto
	\begin{longtable}[c]{
		P{1cm}
		P{1.8cm}
		P{3.2cm}
		P{2.5cm}
		P{\textwidth-8.5cm-10\tabcolsep}
	}
		\coloreintestazione
		\bfseries Ver. & \bfseries Data & \bfseries Nominativo & \bfseries Ruolo & \centering\arraybackslash \bfseries Descrizione
		\endhead
		\csvreader[head to column names, late after line=\\]{#1}{}
		{\versione & \data & \nominativo & \ruolo & \descrizione}
	\end{longtable}
	\pagebreak
}

% tikz logo
\newcommand{\logo}[1]{
	\resizebox{#1}{!}{
		\begin{tikzpicture}
			\draw[fill=black] (22.262,8.488)
			-- (71.362,-52.581)
			-- (7.086,-52.581)
			-- (77.28,-1.254)
			-- (15.686,-49.916)
			-- (64.348,-49.916)
			-- cycle;
		\end{tikzpicture}
	}
}

% Colonne alternative
\newcolumntype{P}[1]{>{\centering\arraybackslash}p{#1}}
\newcolumntype{L}[1]{>{\raggedright\arraybackslash}p{#1}}
\newcolumntype{Y}{>{\centering\arraybackslash}X}

% spaziatura tabelle
\setlength{\extrarowheight}{-1.2pt}
\renewcommand{\arraystretch}{2}

% macros
\renewcommand{\footrulewidth}{0.4pt}
\renewcommand\sectionmark[1]{\markboth{#1}{}} % removes section numbering in the header

% header/footer
\pagestyle{fancy}
\fancyhf{}
\rhead{\leftmark}
\lfoot{\textbf{\vartitolo}}
\rfoot{Pagina \thepage \ di \pageref{LastPage}}

% index the paragraphs and subparagraphs
\setcounter{tocdepth}{5}
\setcounter{secnumdepth}{5}
\titleformat{\paragraph}
{\normalfont\normalsize\bfseries}{\theparagraph}{1em}{}
\titlespacing*{\paragraph}
{0pt}{3.25ex plus 1ex minus .2ex}{1.5ex plus .2ex}
\titleformat{\subparagraph}
{\normalfont\normalsize\bfseries}{\thesubparagraph}{1em}{}
\titlespacing*{\subparagraph}
{0pt}{3.25ex plus 1ex minus .2ex}{1.5ex plus .2ex}

% document first page
\newcommand{\firstpage}{
	\newgeometry{margin=15mm, headsep=15mm}
	\begin{titlepage}
		\begin{center}
			\includegraphics[width=0.5\textwidth]{unipd.png} \\
            \vspace{3mm} \\
			\huge \textbf{Progetto di Tecnologie Web} \\
			\vspace{2mm}
			\vspace{\baselineskip}
			\huge \textbf{\vartitolo}
			\large
		\end{center}
		\setlength{\extrarowheight}{8pt}
		\renewcommand{\arraystretch}{1}
		\rowcolors{0}{white}{white}
		\begin{table}[htbp]
			\centering
			\textbf{Informazioni} \\
			\vspace{1.5mm}
			\setlength\extrarowheight{0.2mm}
			\renewcommand\cellalign{lt}
			\begin{tabular}{r|l}
				\hline \\[-3.5mm]
				\textbf{Componente 1} & \makecell{Diego Stafa & 1226285}  \\
				\textbf{Componente 2} & \makecell{Luciano Wu & 1224452} \\
				\textbf{Componente 3} & \makecell{Samuele Rizzato & 1226307} \\
				\textbf{Anno} & 2021/22 \\
				\textbf{Destinatari} & Prof.ssa. Ombretta Gaggi
			\end{tabular}
		\end{table}
		\begin{center}
			\large \textbf{Sommario}\\
			\centering
			\vardescrizione
		\end{center}
	\end{titlepage}
	\pagebreak

	\newgeometry{margin=30mm, headsep=15mm}
	% Fix warnings about header and footer size
	\setlength{\headheight}{42pt}
	\addtolength{\headsep}{-30pt}
}

\newcommand{\gloss}[1]{\emph{#1}$_{G}$}

\endinput