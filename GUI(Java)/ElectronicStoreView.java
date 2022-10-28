import javafx.scene.layout.Pane;
import javafx.scene.control.ListView;
import java.util.*;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import java.util.Random;
public class ElectronicStoreView extends Pane{
  
int counter=0;
Product[] cartList=new Product[100];
double cartSum=0.00;
int salesvalue=0;
double rev;
double revacc;
int accum=0;
double pervalue;
int[] mostPopular=new int[3];
Product[] topPopular=new Product[3];
int min_idx;
int[] goneItemsAmount=new int[8];
  
ElectronicStore model;
Button reset;
Button add;
Button remove;
Button complete;

TextField sales;
TextField revenue;
TextField salest;

ListView<Product> popular;
ListView<Product> stock;
ListView<Product> cart;

Label popularl;
Label stockl;
Label cartl;
Label salesl;
Label revenuel;
Label sales2l;
Label brackets;

Random rand = new Random();
  
public ElectronicStoreView(ElectronicStore aModel){
 model=aModel;

    reset = new Button("Reset Store");
    reset.relocate(25, 350);
    reset.setPrefSize(145, 45);
    getChildren().add(reset);
    
    add = new Button("Add to Cart");
    add.relocate(280, 350);
    add.setPrefSize(145, 45);
    add.setDisable(true);
    getChildren().add(add);
    
    remove = new Button("Remove from Cart");
    remove.relocate(505, 350);
    remove.setPrefSize(145, 45);
    remove.setDisable(true);
    getChildren().add(remove);
    
    complete = new Button("Complete Sale");
    complete.relocate(651, 350);
    complete.setPrefSize(145, 45);
    complete.setDisable(true);
    getChildren().add(complete);
    //
    sales = new TextField();
    sales.relocate(90, 35);
    sales.setPrefSize(100,10);
    sales.setText(""+0);
    getChildren().add(sales);
    
    revenue = new TextField();
    revenue.relocate(90, 70);
    revenue.setPrefSize(100,10);
    revenue.setText(""+0.00);
    getChildren().add(revenue);
    
    salest = new TextField();
    salest.relocate(90, 105);
    salest.setPrefSize(100,10);
    salest.setText("N/A");
    getChildren().add(salest);
    
    //
    popular = new ListView<Product>();
    popular.relocate(12, 160);
    popular.setPrefSize(180, 180);
    getChildren().add(popular);
    
    stock = new ListView<Product>();
    stock.relocate(205, 30);
    stock.setPrefSize(290, 310);
    getChildren().add(stock);
    
    cart = new ListView<Product>();
    cart.relocate(505, 30);
    cart.setPrefSize(290, 310);
    getChildren().add(cart);
    //
    popularl = new Label("Most Popular Items");
    popularl.relocate(40,136);
    popularl.setPrefSize(200, 1);
    getChildren().add(popularl);
    
    stockl = new Label("Store Stock:");
    stockl.relocate(305,6);
    stockl.setPrefSize(100, 30);
    getChildren().add(stockl);
    
    cartl = new Label("Current Cart:");
    cartl.relocate(610,6);
    cartl.setPrefSize(100, 30);
    getChildren().add(cartl);
    
    salesl = new Label("#Sales:");
    salesl.relocate(35,33);
    salesl.setPrefSize(100, 30);
    getChildren().add(salesl);
    
    revenuel = new Label("Revenue:");
    revenuel.relocate(20,68);
    revenuel.setPrefSize(100, 30);
    getChildren().add(revenuel);
    
    sales2l = new Label("$/Sale:");
    sales2l.relocate(35,103);
    sales2l.setPrefSize(100, 30);
    getChildren().add(sales2l);
    
    brackets = new Label("($0.00)");
    brackets.relocate(700,6);
    brackets.setPrefSize(100, 30);
    getChildren().add(brackets);
    
    update();
    popInitializer();
}
public void clearAll(){
  sales.setText(""+0);
  revenue.setText(""+0.00);
  salest.setText("N/A");
  brackets.setText("("+0.00+")");
  model = ElectronicStore.createStore();
  update();
  updateTop();
  popInitializer();

}
public ListView getStockList(){
  return stock;
}
public Button getAddButton(){
  return add;
}
public Button getRemoveButton(){
  return remove;
}
public Button getCompleteButton(){
  return complete;
}
 public Button getResetButton(){
  return reset;
}
  public Label getBrackets(){
  return brackets;
}
public ListView getCartList(){
  return cart;
}
  
public void update(){
    //
  Product[] temp= new Product[model.getCurproducts()];
  for (int i=0; i<model.getCurproducts();i++){
    temp[i]=model.stock[i];
  }
  ObservableList<Product> list = FXCollections.observableArrayList(temp);
  stock.setItems(list);
    //
    int index = stock.getSelectionModel().getSelectedIndex();
    if(index >= 0){
     add.setDisable(false);
    }else{
     add.setDisable(true);
    }
    int index2 = cart.getSelectionModel().getSelectedIndex();
    if(index2 >= 0){
     remove.setDisable(false);
    }else{
     remove.setDisable(true);
    }
    if (model.counter2>0){
      complete.setDisable(false);
    }else{
      complete.setDisable(true);
}
}
public void updateTop(){
  if (model.cartItems[0]==null){
    cart.getItems().clear();
  }
  Product[] temp1=new Product[model.counter2];
  Product[] mop= model.cartItems;
   for (int p=0; p<model.counter2; p++){
   temp1[p]=mop[p];
   }
   ObservableList<Product> list = FXCollections.observableArrayList(temp1);
   cart.setItems(list);
    }

 public void updateBottom(){
   //
  complete.setDisable(false);
  //
  remove.setDisable(false);
  //
 }
 
 
 public void updateSideway(){
 int index = cart.getSelectionModel().getSelectedIndex();
 if(model.counter2==1){
   model.cartItems[0]=null;
 }
 model.cartItems[index] = null;
 for(int i = index+1; i < model.counter2; i++){
   Product temp = model.cartItems[i-1];
   model.cartItems[i-1] = model.cartItems[i];
   model.cartItems[i] = temp;
 }
 model.counter2--;
 updateTop();
 }
 
public void update5(){
  rev=0;
  if(model.counter2>0){
    for (int p=0;p<model.counter2;p++){
    rev+=model.cartItems[p].getPrice();
    }
    revenue.setText(""+rev);
    revacc+=rev;
    if(model.counter2==1){
      model.cartItems[0]=null;
      model.counter2--;
     }
     int staticCounter=model.counter2;  
     for (int p=0; p<staticCounter; p++){
       model.cartItems[p]=null;
       model.counter2--;
     }
     salesvalue++;
     sales.setText(""+salesvalue);
     updateTop();
     pervalue=revacc/salesvalue;
     salest.setText(""+pervalue);
     //
  }
}
public void updateFinal(){

    for (int d=0; d<model.getCurproducts(); d++){
    goneItemsAmount[d]=model.stock[d].getQuantity();
}
    //if (model.counter3>0){
      //for(int b=0;b<8;b++){
        
    
      
   int min= findMinIdx(goneItemsAmount);
   mostPopular[0]=min;
   goneItemsAmount[min]=100;
   
   min=findMinIdx(goneItemsAmount);
   mostPopular[1]=min;
   goneItemsAmount[min]=100;
   
   min= findMinIdx(goneItemsAmount);
   mostPopular[2]=min;
   goneItemsAmount[min]=100;
   
   for(int k=0;k<3;k++){
     if (mostPopular[k]==0){
       topPopular[k]=new Desktop(100, 10, 3.0, 16, false, 250, "Compact");
       
  }
     else if (mostPopular[k]==1){
      topPopular[k]=new Desktop(200, 10, 4.0, 32, true, 500, "Server");
  
     }
      else if (mostPopular[k]==2){
       topPopular[k]=new Laptop(150, 10, 2.5, 16, true, 250, 15);
    
     }
       else if (mostPopular[k]==3){
       topPopular[k]= new Laptop(250, 10, 3.5, 24, true, 500, 16);
         
     }
        else if (mostPopular[k]==4){
       topPopular[k]=new Fridge(500, 10, 250, "White", "Sub Zero", 15.5, false);
        
     }
         else if (mostPopular[k]==5){
       topPopular[k]=new Fridge(750, 10, 125, "Stainless Steel", "Sub Zero", 23, true);
        
     }
          else if (mostPopular[k]==6){
       topPopular[k]= new ToasterOven(25, 10, 50, "Black", "Danby", 8, false);
         
     }
           else if (mostPopular[k]==7){
       topPopular[k]=new ToasterOven(75, 10, 50, "Silver", "Toasty", 12, true);
      
     }
   }
     ObservableList<Product> list2 = FXCollections.observableArrayList(topPopular);
     popular.setItems(list2);
   

}


public int findMinIdx(int[] numbers) {
    if (numbers == null || numbers.length == 0) return -1; // Saves time for empty array
    // As pointed out by ZouZou, you can save an iteration by assuming the first index is the smallest
    int minVal = numbers[0]; // Keeps a running count of the smallest value so far
    int minIdx = 0; // Will store the index of minVal
    for(int idx=1; idx<numbers.length; idx++) {
        if(numbers[idx] < minVal) {
            minVal = numbers[idx];
            minIdx = idx;
        }
    }
  return minIdx;
}

public void popInitializer(){
  Product[] temp1= new Product[3];
  for (int i=0; i<3;i++){
    temp1[i]=model.stock[i];
  }
  ObservableList<Product> list1 = FXCollections.observableArrayList(temp1);
  popular.setItems(list1);
  }

public void deal(){
  rev=0;
  if(model.counter2>=0){
    for (int p=0;p<model.counter2;p++){
    rev+=model.cartItems[p].getPrice();
    }
   brackets.setText("("+""+rev+")");
  }
}
}



  






  






  



    

  
 
