package personnel;

import java.rmi.server.*;
import java.rmi.*;

/**
 * Copyright (c) 2015 Tim Lindquist,
 * Software Engineering,
 * Arizona State University at the Polytechnic campus
 * <p/>
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation version 2
 * of the License.
 * <p/>
 * This program is distributed in the hope that it will be useful,
 * but without any warranty or fitness for a particular purpose.
 * <p/>
 * Please review the GNU General Public License at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 * see also: https://www.gnu.org/licenses/gpl-faq.html
 * so you are aware of the terms and your rights with regard to this software.
 * Or, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,USA
 * <p/>
 * Purpose: demonstrate using the RMI API
 * Implementation of employee server - create a remote server object 
 * (with a couple of employees). Register the remote server object with the
 * rmi registry.
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * @see <a href="http://pooh.poly.asu.edu/Ser321">Ser321 Home Page</a>
 * @author Tim Lindquist (Tim.Lindquist@asu.edu) CIDSE - Software Engineering
 *                       Ira Fulton Schools of Engineering, ASU Polytechnic
 * @date    August, 2015
 * @license See above
 */
class EmpServerImpl extends UnicastRemoteObject implements EmpServer {

   protected Emp empList[] = {new Emp("Bob", 100), new Emp("Sue", 200)};

   public EmpServerImpl() throws RemoteException {
   }

   public Emp getEmp(int id) throws RemoteException {
      Emp ret = null;
      for (int i=0; i < empList.length; i++){
         if (empList[i].getId() == id){
            System.out.println("Completing request for employee "+id);
            ret = empList[i];
            break;
         }
      }
      return ret;
   }

   public static void main(String args[]) {
      try {
         String hostId="localhost";
         String regPort="2222";
         if (args.length >= 2){
	    hostId=args[0];
            regPort=args[1];
         }
         //System.setSecurityManager(new RMISecurityManager()); // rmisecmgr deprecated
         EmpServer obj = new EmpServerImpl();
         Naming.rebind("rmi://"+hostId+":"+regPort+"/EmployeeServer", obj);
         System.out.println("Server bound in registry as: "+
                            "rmi://"+hostId+":"+regPort+"/EmployeeServer");
      }catch (Exception e) {
         e.printStackTrace();
      }
   }
}
