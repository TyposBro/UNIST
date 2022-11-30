lazy val root = (project in file(".")).
  settings(
    inThisBuild(List(
      organization := "com.example",
      scalaVersion := "2.13.3"
    )),
    name := "hw4-cse271"
  )
lazy val AntlrVersion     = "4.8-1"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.0" % Test
libraryDependencies += "com.lihaoyi" %% "fastparse" % "2.2.2"
libraryDependencies += "org.antlr"     % "antlr4"     % AntlrVersion


enablePlugins(Antlr4Plugin)
antlr4Version in Antlr4 := AntlrVersion // default: 4.8-1
antlr4PackageName in Antlr4 := Some("hw4")
antlr4GenListener in Antlr4 := false
antlr4GenVisitor in Antlr4 := true