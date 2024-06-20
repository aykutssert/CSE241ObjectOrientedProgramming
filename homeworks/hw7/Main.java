
public class Main {

    public static void main(String arg[]) {

        Dataset ds = new Dataset();

        Player p1 = new Player("p1"); //Player1 is p1.
        Player p2 = new Player("p2"); //Player2 is p2.
        Viewer v1 = new Viewer("v1");  //Viewer1 is v1.
        Viewer v2 = new Viewer("v2");   //Viewer2 is v2.


        //Dataset should support registering;
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);
        // Dataset should also support un-registering.
        ds.unregister(p1);

        // Here we create different objects.
        ds.add(new Image("imagename1", "dimension info1", "other info1"));
        ds.add(new Image("imagename2", "dimension info2", "other info2"));
        ds.add(new Image("imagename3", "dimension info3", "other info3"));
        ds.add(new Image("imagename4", "dimension info4", "other info4"));
        ds.add(new Image("imagename5", "dimension info5", "other info5"));

        ds.add(new Audio("audioname1", "duration1", "other info1"));
        ds.add(new Audio("audioname2", "duration2", "other info2"));
        ds.add(new Audio("audioname3", "duration3", "other info3"));


        ds.add(new Video("videoname1", "duration1", "other info1"));
        // if name is same , object is not added to dataset.
        ds.add(new Video("videoname1", "duration1", "other info1"));                                               
        ds.add(new Video("videoname2", "duration2", "other info2"));
        ds.add(new Video("videoname3", "duration3", "other info3"));

        ds.add(new Text("textname1", "other info1"));
        ds.add(new Text("textname2", "other info2"));
        ds.add(new Text("textname3", "other info3"));
        // if name is same , object is not added to dataset                                                      
        ds.add(new Text("textname3", "other info4"));



        // Lets use one of the player objects.

        // We can get the currently playing object
        p1.next("video"); // Current Object is must be videoname1
        p1.next("video"); // Current Object is must be videoname2
        p1.previous("video"); // Current Object is must be videoname1.
        Playable po = p1.currently_playing();

      

        if (po != null) {

            System.out.println();

            po.info();   // This prints info about the playing object.
            po.play();     // the playing object will play.

            // we can remove this object from the dataset
            ds.remove((ObjectBase) po);

            System.out.println();
        }


        v1.next("text");    //textname1
        v1.previous("image"); //imagename5
        // similarly, viewer object:
        NonPlayable np = v1.currently_viewing();  //"np must be imagename5"

        if (np != null) {

            System.out.println();

            np.info();// this prints info about the object being viewed.
            np.display(); //the viewing object will display.

            // we can remove this object from the dataset
            ds.remove((ObjectBase) np);

            System.out.println();
        }

        v2.next("text");//textname1
        v2.previous("image"); //imagename4
         // similarly, viewer object:
         NonPlayable np2 = v2.currently_viewing();

         if (np2 != null) {
 
             System.out.println();
 
             np2.info();// this prints info about the object being viewed.
             np2.display(); //the viewing object will display.
 
             // we can remove this object from the dataset
             ds.remove((ObjectBase) np2);
 
             System.out.println();
         }

         System.out.println("P1 playlist like this:");
         p1.showList();
         System.out.println();
         System.out.println("P2 playlist like this:");
         p2.showList();
         System.out.println();
         System.out.println("V1 viewList like this:");
         v1.showList();
         System.out.println();
         System.out.println("V2 viewList like this:");
         v2.showList();

    }

}