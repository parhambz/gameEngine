package xo;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Main extends Application {
    static String MAIN_THEME = Utils.LIGHT_THEME;

    @Override
    public void start(Stage primaryStage) throws Exception {


        //making "about us" scene
        AboutUi aboutUi = new AboutUi();
        Text text = new Text(Utils.LOREM);
        text.setWrappingWidth(Utils.M_W_SIZE - 20);
        Button back = new Button("Back");
        aboutUi.addText(text);
        aboutUi.addButton(back);
        aboutUi.setPadding(new Insets(Utils.M_P_SIZE));
        aboutUi.getStylesheets().add(MAIN_THEME);

        //making "menu" scene
        MenuUi menuUi = new MenuUi();
        menuUi.getStylesheets().add(MAIN_THEME);
        Button oneByOne = new Button("1 vs. 1");
        Button oneByBot = new Button("1 vs. Bot");
        Button about = new Button("About Us");
        Button exit = new Button("Exit");

        menuUi.addAllButtons(oneByOne, oneByBot, about, exit);

        //scenes
        Scene about_scene = new Scene(aboutUi, Utils.M_W_SIZE, Utils.M_H_SIZE);
        Scene menu_scene = new Scene(menuUi, Utils.M_W_SIZE, Utils.M_H_SIZE);

        //onActions
        about.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {

                //going to about us scene
                primaryStage.setScene(about_scene);
                primaryStage.setTitle(Utils.ABOUT_TITLE);
            }
        });

        back.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                primaryStage.setScene(menu_scene);

            }
        });

        exit.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                Platform.exit();
            }
        });

        //making first stage
        primaryStage.setScene(menu_scene);
        primaryStage.setTitle(Utils.MENU_TITLE);

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
