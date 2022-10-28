import java.util.ArrayList;
public class TrieMap implements TrieMapInterface{
  TrieMapNode root;
  String finalval;
  boolean finalVerdict;

  public TrieMap(){
  root=new TrieMapNode();
  finalval=null;
  finalVerdict=false;


  }

  //Indirectly recursive method to meet definition of interface
  public void put(String key, String value){
  put(root,key,value);
  }

  //Recursive method
  private void put(TrieMapNode current, String curKey, String value){
    if (curKey.length()==0){
      current.setValue(value);
      return;
    }
    if (current.getChildren().containsKey(curKey.charAt(0))){
      this.put(current.getChildren().get(curKey.charAt(0)),curKey.substring(1),value);
      return;
    }else{
     current.getChildren().put(curKey.charAt(0),new TrieMapNode());
     this.put(current.getChildren().get(curKey.charAt(0)),curKey.substring(1),value);
     return;
      }
  }


  //Indirectly recursive method to meet definition of interface
  public String get(String key){
    return get(root,key);
  }

  //Recursive method
  public String get(TrieMapNode current, String curKey){
    if (curKey.length()==0 && current.getValue()!=null){
      finalval=current.getValue();
    }else{
    if (current.getChildren().containsKey(curKey.charAt(0))){
      get(current.getChildren().get(curKey.charAt(0)),curKey.substring(1));
    }else{
    finalval= null;
  }
  }
        return finalval;
  }

 //Indirectly recursive method to meet definition of interface
  public boolean containsKey(String key){
    return containsKey(root,key,key);
  }

  //Recursive method
  public boolean containsKey(TrieMapNode current, String curKey,String curKey1){
    if (curKey.length()==0){
      if(current.getValue()==curKey1){
      finalVerdict=true;
    }
    }else{
    if (current.getChildren().containsKey(curKey.charAt(0))){
    containsKey(current.getChildren().get(curKey.charAt(0)),curKey.substring(1),curKey1);
    }else{
      finalVerdict=false;
    }
  }
    return finalVerdict;
  }


  //Indirectly recursive method to meet definition of interface
  public ArrayList<String> getValuesForPrefix(String prefix){
    ArrayList<String> temp=new ArrayList<>();
    ArrayList<String> finalone =getValuesForPrefix(root,temp,prefix);
    ArrayList<String> finaltwo =new ArrayList<>();
    for(int i=0;i<finalone.size();i++){
      if (finalone.get(i).startsWith(prefix)){
        finaltwo.add(finalone.get(i));
      }
    }
    return finaltwo;
  }

  public ArrayList<String> getValuesForPrefix(TrieMapNode current,ArrayList<String> pop,String prefix){
    if (current.getChildren()==null && current.getValue()==null){
      return null;
    }else{
        for(Character char1 : current.getChildren().keySet()){
          if (current.getChildren().get(char1).getValue()!=null){
            pop.add(current.getChildren().get(char1).getValue());
          }
          if (current.getChildren().get(char1).getChildren()!=null){
            getValuesForPrefix(current.getChildren().get(char1),pop,prefix);
          }
        }
       }
    return pop;
    }

  //Recursive helper function to find node that matches a prefix
  public TrieMapNode findNode(TrieMapNode current, String curKey){
    return null;
  }

  //Recursive helper function to get all keys in a node's subtree
  public ArrayList<String> getKeys(TrieMapNode current){
    return new ArrayList<String>();
  }

  //Indirectly recursive method to meet definition of interface
  public void print(){
  print(root);
  }

  //Recursive method to print values in tree
  public void print(TrieMapNode current){
    if (current.getChildren()==null && current.getValue()==null){
      return;
    }else{
        for(Character char1 : current.getChildren().keySet()){
          if (current.getChildren().get(char1).getValue()!=null){
            System.out.println(current.getChildren().get(char1).getValue());
          }
          if (current.getChildren().get(char1).getChildren()!=null){
            this.print(current.getChildren().get(char1));
          }
        }
    }
  }

  public static void main(String[] args){
    //You can add some code in here to test out your TrieMap initially
    //The TrieMapTester includes a more detailed test
  }
}

  /*  char a_char = curKey.charAt(0);
  if(current.getChildren().containsKey(a_char)){
  put(current.getChildren().get(a_char),curKey.substring(1),value);
  }else{
  if(curKey.length()!=0){
  current.getChildren().put(a_char,new TrieMapNode());
  put(current.getChildren().get(a_char),curKey.substring(1),value);
  }else{
  current.getChildren().put(a_char,new TrieMapNode(value));
  }
  }
  }*/
