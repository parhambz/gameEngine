package xo;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {

        //making menu scene
        MenuUi menuUi = new MenuUi();
        Button oneByOne = new Button("1 vs. 1");
        Button oneByBot = new Button("1 vs. Bot");
        Button about = new Button("About Us");
        Button exit = new Button("Exit");

        menuUi.addAllButtons(oneByOne, oneByBot, about, exit);


        //making Stage
        makingStage(primaryStage, menuUi, "Game", 500, 500);

        //show stage
        primaryStage.show();
    }

    public static void makingStage(Stage primaryStage, Parent root, String title, int width, int height) {
        primaryStage.setTitle(title);
        Scene scene = new Scene(root, width, height);
        scene.setFill(Color.BLUE);
        primaryStage.setScene(scene);

    }


    public static void main(String[] args) {
        launch(args);
    }
}
