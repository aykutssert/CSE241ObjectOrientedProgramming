
import java.util.ArrayList;

class Viewer implements IObserver {

    private String name; //observer name
    private ArrayList<NonPlayable> viewList; //viewList for observer
    private int currentIndex; //current object

    public Viewer(String _name) {
        this.name = _name;
        viewList = new ArrayList<NonPlayable>();
        currentIndex = 0;
    }

    @Override
    public void update(ObjectBase object) {
        try {
            if (object.getFlag() == 1) { // If the flag of the object is 1 (add operation)
                for (var item : viewList) {
                    ObjectBase item2 = (ObjectBase)item;
                    // If there is an object with the same name in the viewList, stop the process and return
                    if (item2.getName() == object.getName()) { 
                        return;
                    }
                }
                viewList.add((NonPlayable)object); // add object to viewList
                System.out.println(object.getName() + " is added to " + this.name + "'s viewList");
            }
            if (object.getFlag() == 2) { // If the flag value of the object is 2 (delete operation)
                if (viewList.contains((NonPlayable)object)) { // If there is an object in the viewList, remove the object
                    viewList.remove((NonPlayable)object);
                    System.out.println(object.getName() + " is deleted from " + this.name + "'s viewList");
                }
                if (viewList.size() == 0) {  // Throw NullPointerException if viewList is empty
                    throw new NullPointerException("There is no next item because ViewList " + name + " is empty");
                }

            }
        } catch (NullPointerException e) {
            System.out.println(e.getMessage()); // Print message to screen when NullPointerException occurs
        }
        

    }

      //getter for viewList.
    public ArrayList<NonPlayable> getViewList() {
        return viewList;
    }


     //show the all objects in list.
    public void showList() {
        if(viewList.size()==0){
            System.out.println("ViewList is empty for "+name);
            return;
          }
        for (var item : viewList) {
            item.info();
        }
    }

    //getter for name for viewer observer.
    @Override
    public String getName() {
        return name;
    }

    public NonPlayable currently_viewing() {
        try {
            // Throw NullPointerException if viewList is empty
            if (viewList.size() == 0) {
                throw new NullPointerException("ViewList is empty");
            }
        }
        // Get the message if NullPointerException is caught  
        catch (NullPointerException e) {
            e.getMessage();
        }

        // If currentIndex is a valid index
        if (currentIndex >= 0 && currentIndex < viewList.size()) {
            // return the object in the viewList corresponding to the currentIndex (casted)
            return (NonPlayable) viewList.get(currentIndex);

        }
        // If there is no valid index, return null
        return null;
    }

    //next function
    public void next(String type) {

        if (type.equals("image")) { //if type is image
            currentIndex = getNextIndex(type); //fetch the next image object.
        }
        if (type.equals("text")) { //if type is text
            currentIndex = getNextIndex(type); //fetch the next text object.
        }
    }


    //previous function
    public void previous(String type) {
        if (type.equals("image")) {  //if type is audio
            currentIndex = getPreviousIndex(type); //fetch the previous image object.
        }
        if (type.equals("text")) {  //if type is audio
            currentIndex = getPreviousIndex(type); //fetch the previous text object.
        }
    }

    public int getNextIndex(String type) {
        // If type is "image"
        if (type.equals("image")) {
            // loop through indexes after currentIndex
            for (int i = currentIndex + 1; i < viewList.size(); i++) {
                // if the object in the viewList is of image type
                if (viewList.get(i) instanceof Image) {
                    // Return the corresponding index
                    return i;
                }
            }
        }
        // If the type is "text"
        if (type.equals("text")) {
            // loop through indexes after currentIndex
            for (int i = currentIndex + 1; i < viewList.size(); i++) {
                // if the object in the viewList is of Text type
                if (viewList.get(i) instanceof Text) {
                    // Return the corresponding index
                    return i;
                }
            }
        }
        // Return currentIndex if the type is not "image" or "text" or the appropriate index is not found
        return currentIndex;
    }

    public int getPreviousIndex(String type) {
         // If type is "image"
        if (type.equals("image")) {
            // loop through indexes before currentIndex
            for (int i = currentIndex - 1; i >= 0; i--) {
                // if the object in the viewList is of Image type
                if (viewList.get(i) instanceof Image) {
                     // Return the corresponding index
                    return i;
                }
            }
        }
        // If the type is "text"
        if (type.equals("text")) {
            // loop through indexes before currentIndex
            for (int i = currentIndex - 1; i >= 0; i--) {
                // if the object in the viewList is of Text type
                if (viewList.get(i) instanceof Text) {
                     // Return the corresponding index
                    return i;
                }
            }
        }

         // Return currentIndex if the type is not "image" or "text" or the appropriate index is not found
        return currentIndex;
    }

}