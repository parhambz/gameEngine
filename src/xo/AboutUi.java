package xo;

import javafx.scene.text.Text;

/**
 * Created by nima on 1/23/2019 AD.
 */
public class AboutUi extends MenuUi {

    AboutUi(){
        Log.d("Game","About Us Created");
    }

    public void addText(Text text){
        this.list.add(text);
        //Todo:Log.d("");
    }

    public void addAllText(Text... texts){
        this.list.addAll(texts);
        //Todo:Log.d("");
    }

}
