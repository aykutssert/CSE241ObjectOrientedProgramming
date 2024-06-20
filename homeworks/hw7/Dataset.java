
import java.util.ArrayList;


public class Dataset {

    private ArrayList<ObjectBase> data = new ArrayList<ObjectBase>(); //object data
    private ArrayList<IObserver> observers = new ArrayList<IObserver>(); //observer data


    /**
     * 
     * @return {@code data}
     */
    public ArrayList<ObjectBase> getData() {
        return data;
    }

    /**
     * add an object to data list
     * 
     * @param object
     */
    public void add(ObjectBase object) {
        object.setFlag(1);
        data.add(object);
        notifyObservers(object);
    }

    /**
     * remove an object from data list
     * 
     * @param object
     */

    public void remove(ObjectBase object) {
        if(data.size()!=0){
        object.setFlag(2);
        data.remove(object);
        notifyObservers(object);
        }
    }

    /**
     * register an observer to observers list
     * 
     * @param observer
     */

    public void register(IObserver observer) {


        observers.add(observer);
        System.out.println("observer "+observer.getName()+ " added to list");

    }

    /**
     * delete an observer of observers list
     * 
     * @param observer
     */

    public void unregister(IObserver observer) {
        observers.remove(observer);
        System.out.println("observer "+observer.getName()+ " deleted from list");
    }

    /**
     * 
     * @param object we search the observers list and if the object is Playable type
     *               then Player observer know update.
     *               if the object is NonPlayable type then Viewer observer know
     *               update.
     */

    private void notifyObservers(ObjectBase object) {

        for (IObserver observer : observers) {

            // If the object is of type Playable and observer is of type Player
            if (object instanceof Playable && observer instanceof Player) {
                observer.update(object); // update observer
            } 

            // If the object is of type NonPlayable and observer is of type Viewer
            else if (object instanceof NonPlayable && observer instanceof Viewer) {

                observer.update(object);// update observer
            }

        // Do nothing for other cases
         // In this case we are not updating the observer
        }
    }

}