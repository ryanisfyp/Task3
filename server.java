import java.net.*;
import java.io.*;
import java.util.*;
 
public class server {
 
public static void main(String[] args) throws Exception{
 
DatagramSocket ss=new DatagramSocket(7777);
 
while(true){

System.out.println("---------------------------------"); 
System.out.println("Waiting for connection....");
 
byte[] rd=new byte[100];
byte[] sd=new byte[100];
 
DatagramPacket rp=new DatagramPacket(rd,rd.length);
 
ss.receive(rp);
 
InetAddress ip= rp.getAddress();
 
int port=rp.getPort();
 
Date d=new Date();  
 
String time= d + ""; 
 
sd=time.getBytes();  
 
DatagramPacket sp=new DatagramPacket(sd,sd.length,ip,port);
 
ss.send(sp);
 
rp=null;
 
System.out.println("Time sent to client: " + time);
System.out.println("---------------------------------");
System.out.println("");
 
}
 
}
 
}
