import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.event.*;
import javafx.scene.input.*;
import javafx.scene.control.Label;

public class ElectronicStoreApp extends Application{

  ElectronicStore model;
  ElectronicStoreView view;
  
  public void start(Stage primaryStage){
    model = ElectronicStore.createStore();
    view = new ElectronicStoreView(model);
    
    //listeners
    view.getStockList().setOnMouseReleased(new EventHandler<MouseEvent>() {
      public void handle(MouseEvent e){handleStockListSelection(); }
    });
    view.getCartList().setOnMouseReleased(new EventHandler<MouseEvent>() {
      public void handle(MouseEvent e){handleCartListSelection(); }
    });
    view.getAddButton().setOnAction(new EventHandler<ActionEvent>() {
      public void handle(ActionEvent actionEvent) {handleAddButton(); }
    });
     view.getRemoveButton().setOnAction(new EventHandler<ActionEvent>() {
      public void handle(ActionEvent actionEvent) {handleRemoveButton(); }
    });
     view.getCompleteButton().setOnAction(new EventHandler<ActionEvent>() {
      public void handle(ActionEvent actionEvent) {handleCompleteButton(); }
    });
     view.getResetButton().setOnAction(new EventHandler<ActionEvent>() {
      public void handle(ActionEvent actionEvent) {handleResetButton(); }
    });
  
    primaryStage.setTitle("Electronic Store Application");
    primaryStage.setResizable(false);
    primaryStage.setScene(new Scene(view, 800,400)); // Set size of window
    primaryStage.show();
   }
     public static void main(String[] args) { launch(args); }
     
    //handlers
    public void handleStockListSelection(){
    view.update();
}
    public void handleAddButton(){
    int index=view.getStockList().getSelectionModel().getSelectedIndex();
    if (index >=0){
    model.sellProducts(index,1);
    view.update();
    view.updateTop();
    view.deal();
    }
}
    public void handleCartListSelection(){
    view.updateBottom();
}
    public void handleCompleteButton(){
    view.update5();  
    view.updateFinal();
    view.getBrackets().setText("(0.00)");
    }
      
    public void handleRemoveButton(){
    int index=view.getCartList().getSelectionModel().getSelectedIndex();
    if (index >=0){
    Product chosen=model.cartItems[index];
    if (chosen.getQuantity()==0){
    model.addProduct(chosen);
    }
    chosen.addSetQuantity();
    view.updateSideway();
    view.update();
    view.deal();

}
}
    public void handleResetButton(){
    Desktop d1 = new Desktop(100, 10, 3.0, 16, false, 250, "Compact");
    Desktop d2 = new Desktop(200, 10, 4.0, 32, true, 500, "Server");
    Laptop l1 = new Laptop(150, 10, 2.5, 16, true, 250, 15);
    Laptop l2 = new Laptop(250, 10, 3.5, 24, true, 500, 16);
    Fridge f1 = new Fridge(500, 10, 250, "White", "Sub Zero", 15.5, false);
    Fridge f2 = new Fridge(750, 10, 125, "Stainless Steel", "Sub Zero", 23, true);
    ToasterOven t1 = new ToasterOven(25, 10, 50, "Black", "Danby", 8, false);
    ToasterOven t2 = new ToasterOven(75, 10, 50, "Silver", "Toasty", 12, true);
    model.stockclear();
    model.addProduct(d1);
    model.addProduct(d2);
    model.addProduct(l1);
    model.addProduct(l2);
    model.addProduct(f1);
    model.addProduct(f2);
    model.addProduct(t1);
    model.addProduct(t2);
    model.counter2=0;
    model.cartItems=new Product[8];
    view.clearAll();

}
}

    

     
     




