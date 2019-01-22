package xo;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));

        //Making Stage
        makingStage(primaryStage, root, "Game", 500, 500);



        //show stage
        primaryStage.show();
    }

    public static void makingStage(Stage primaryStage, Parent root, String title, int width, int height) {
        primaryStage.setTitle(title);
        Scene scene = new Scene(root,width,height);
        scene.setFill(Color.BLUE);
        primaryStage.setScene(scene);

    }


    public static void main(String[] args) {
        launch(args);
    }
}
