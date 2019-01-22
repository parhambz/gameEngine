package xo;


import javafx.collections.ObservableList;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
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

    public void addImage(ImageView imageView){
        list.add(imageView);
        Log.d("Image Added to Menu", "Image added");
    }

    public void addAllImage(ImageView...imageViews){
        list.addAll(imageViews);
        Log.d("Images Added to Menu", "All Images added to menu");
    }

}
