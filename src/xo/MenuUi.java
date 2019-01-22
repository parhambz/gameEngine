package xo;


import javafx.collections.ObservableList;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;


public class MenuUi extends VBox {

    private double SPACE_SIZE = 10;
    ObservableList list;

    MenuUi() {
        list = this.getChildren();
        this.setSpacing(SPACE_SIZE);
        Log.d("Game", "Menu Created");
    }

    public void addButton(Button button) {
        list.add(button);
        Log.d("Button Added to Menu", button.getText().toString());
    }

    public void addAllButtons(Button... buttons){
        list.addAll(buttons);
        Log.d("Buttons Added to Menu", "All Buttons added to menu");
    }

}
