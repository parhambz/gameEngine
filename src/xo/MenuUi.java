package xo;


import javafx.collections.ObservableList;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;


public class MenuUi extends VBox {

    private double SPACE_SIZE = 10;
    ObservableList list;

    MenuUi(){
        list = this.getChildren();
        this.setSpacing(SPACE_SIZE);
        System.out.println("Menu Created!");
    }

    public void addButton(Button button){
        list.add(button);
        System.out.println(button.getText().toString() + " Button Added to Menu!");
    }

}
