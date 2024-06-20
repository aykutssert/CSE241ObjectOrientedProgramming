import java.util.ArrayList;

class Player implements IObserver {

  private String name; //observer name
  private ArrayList<Playable> playList; //playList for observer
  private int currentIndex; //current object
 
  public Player(String _name) {
    this.name = _name;
    playList = new ArrayList<Playable>();
    currentIndex = 0;

  }


  @Override
  public void update(ObjectBase object) {
    try {
      if (object.getFlag() == 1) {  // If the flag of the object is 1 (add operation)

    

        for (var item : playList) {
          ObjectBase item2 = (ObjectBase)item;

          if (item2.getName() == object.getName()) { // If there is an object with the same name in the playList, stop the process and return
            return;
          }
        }

        playList.add((Playable)object); // add object to playList
        System.out.println(object.getName() + " is added to " + this.name + "'s playList");

      }
      if (object.getFlag() == 2) {                     // If the flag value of the object is 2 (delete operation)
        if (playList.contains((Playable)object)) {     // If there is an object in the playList, remove the object
          playList.remove((Playable)object);
          System.out.println(object.getName() + " is deleted from " + this.name + "'s playList");


          if (playList.size() == 0) {          // Throw NullPointerException if playList is empty
            throw new NullPointerException("There is no next item because PlayList "+ name+ " is empty");
          }



        }

      }
    } catch (NullPointerException e) {
      System.out.println(e.getMessage());// Print message to screen when NullPointerException occurs
    }
  }

  //show the all objects in list.
  public void showList() {
    if(playList.size()==0){
      System.out.println("PlayList is empty for "+name);
      return;
    }
    for (var item : playList) {
      item.info(); //print a object info.
    }
  }
  
  //getter for Playlist.
  public ArrayList<Playable> getPlayList() {
    return playList;
  }


  //getter for name for player observer.
  @Override
  public String getName() {
    return name;
  }

  //next object
  public void next(String type) {
    
      if (type.equals("audio")) { //if type is audio
        currentIndex = getNextIndex(type); //fetch the next audio object.
      }
      if (type.equals("video")) { //if type is video
        currentIndex = getNextIndex(type);//fetch the next video object.
      }
  }


  public void previous(String type) {
    if (type.equals("audio")) {  //if type is audio
      currentIndex = getPreviousIndex(type); //fetch the previous audio object.
    }
    if (type.equals("video")) { //if type is video
      currentIndex = getPreviousIndex(type); //fetch the previous video object.
    }
  }


  public int getNextIndex(String type) {
    // If type is "video"
    if (type.equals("video")) { 
      // loop through indexes after currentIndex
      for (int i = currentIndex + 1; i < playList.size(); i++) {
        if (playList.get(i) instanceof Video) { // if the object in the playList is of Video type
          return i; // Return the corresponding index
        }
      }
    }
    // If the type is "audio"
    if (type.equals("audio")) {
      // loop through indexes after currentIndex
      for (int i = currentIndex + 1; i < playList.size(); i++) {
        if (playList.get(i) instanceof Audio) { // if the object in the playList is of  Audio type
          return i; // Return the corresponding index
        }
      }
    }
    
    // Return currentIndex if the type is not "video" or "audio" or the appropriate index is not found
    return currentIndex;
  }

  public int getPreviousIndex(String type) {
    // If type is "video"
    if (type.equals("video")) {
      // loop through indexes before currentIndex
      for (int i = currentIndex - 1; i >= 0; i--) {
        // if the object in the playList is of Video type
        if (playList.get(i) instanceof Video) {
          // Return the corresponding index
          return i;
        }
      }
    }
    // If the type is "audio"
    if (type.equals("audio")) {
      // loop through indexes before currentIndex
      for (int i = currentIndex - 1; i >= 0; i--) {
        // if the object in the playList is of type Audio
        if (playList.get(i) instanceof Audio) {
          // Return the corresponding index
          return i;
        }
      }
    }
    // Return currentIndex if the type is not "video" or "audio" or the appropriate index is not found
    return currentIndex;
  }


  public Playable currently_playing() {
    try {
      // Throw NullPointerException if playList is empty
      if (playList.size() == 0) {
        throw new NullPointerException("PlayList is empty");
      }
    }
    // Get the message if NullPointerException is caught 
    catch (NullPointerException e) {
      e.getMessage();
    }
    
    // If currentIndex is a valid index
    if (currentIndex >= 0 && currentIndex < playList.size()) {
      // return the object in the playList corresponding to the currentIndex (casted)
      return (Playable) playList.get(currentIndex);
    }

    // If there is no valid index, return null
    return null;
    

  }
}
