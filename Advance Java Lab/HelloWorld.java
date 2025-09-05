/* Objective : Write a Program to implement Applet in Java
 What is Applet?
  A Java Applet is small Java program that can be embedded in a Web Page and runs inside a Web Browser on the Client
  Side. Applet are Mainly used to create dynamic and interactive content on websites.

  Key Points about Applet
  -> All Applets are Subclasses of Java.applet.Applet Class directly or Indirectly
  -> Applets are not Stand alone application, They run inside a web browser or an applet viewer
  -> Applet are Not used main method to start execution
  -> Output is not sole using System.out.println instead AWT methods like drawString() are used for graphical output

  Applet Life Cycle

  1. Init()
  2. Start() Method
  3. Paint() Method
  4. Stop() Method
  5. Destroy() Method

  Q1. Write a Program to create HelloWorld in Applet
  Q2. Write a Program to set the color of the applet and draw a fill oval shape
 */
import javax.swing.*;
import java.applet.Applet;
import java.awt.*;

/*< applet code= "HelloWorld.class" Width = "300" Height = "200"></applet>*/
public class HelloWorld extends Applet{
    public void paint(Graphics g){
        g.drawString("Hello World",100,100);
        setBackground(Color.black);
        g.setColor(Color.black);
        g.drawOval(45,56,100,100);
        g.fillOval(45,56,100,100);
    }
}


