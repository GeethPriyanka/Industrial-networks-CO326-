import javafx.application.Application; 

import javafx.geometry.Insets; 
import javafx.geometry.Pos; 

import javafx.scene.Scene; 
import javafx.scene.control.ChoiceBox; 
import javafx.scene.control.RadioButton; 
import javafx.scene.control.TextArea;
import javafx.scene.layout.GridPane; 
import javafx.scene.text.Text; 
import javafx.scene.control.TextField; 
import javafx.scene.control.ToggleGroup;  
import javafx.stage.Stage; 
         
public class Thermometer extends Application { 
   @Override 
   public void start(Stage stage) {    
      //Label for name 
      Text tempLabel = new Text("Temperature"); 
      
      TextArea temp = new TextArea();
      temp.setEditable(false);
       
      //Label for gender
      Text tempUnitsLabel = new Text("Units"); 
      
      //Toggle group of radio buttons       
      ToggleGroup groupUnits = new ToggleGroup(); 
      RadioButton celsiusRadio = new RadioButton("celsius"); 
      celsiusRadio.setToggleGroup(groupUnits); 
      RadioButton farenhiteRadio = new RadioButton("farenhite"); 
      farenhiteRadio.setToggleGroup(groupUnits);  
      
      //Label for location 
      Text thermometerLabel = new Text("Thermometer"); 
      
      //Choice box for location 
      ChoiceBox locationchoiceBox = new ChoiceBox(); 
      locationchoiceBox.getItems().addAll
         ("Thermometer 1", "Thermometer 2", "Thermometer 3"); 
      
      //Creating a Grid Pane 
      GridPane gridPane = new GridPane();    
      
      //Setting size for the pane 
      gridPane.setMinSize(300, 200); 
       
      //Setting the padding    
      gridPane.setPadding(new Insets(10, 10, 10, 10));  
      
      //Setting the vertical and horizontal gaps between the columns 
      gridPane.setVgap(5); 
      gridPane.setHgap(10);       
      
      //Setting the Grid alignment 
      gridPane.setAlignment(Pos.CENTER); 
       
      //Arranging all the nodes in the grid 
      gridPane.add(tempLabel, 0, 0); 
      gridPane.add(temp, 1, 0); 
      
      gridPane.add(tempUnitsLabel, 0, 2); 
      gridPane.add(celsiusRadio, 1, 2);       
      gridPane.add(farenhiteRadio, 2, 2);     
       
      gridPane.add(thermometerLabel, 0, 6); 
      gridPane.add(locationchoiceBox, 1, 6);    
       
      tempLabel.setStyle("-fx-font: normal bold 15px 'serif' "); 
       
      tempUnitsLabel.setStyle("-fx-font: normal bold 15px 'serif' "); 
       
      thermometerLabel.setStyle("-fx-font: normal bold 15px 'serif' "); 
      temp.setStyle("-fx-font: normal bold 15px 'serif' ");
      //Setting the back ground color 
      gridPane.setStyle("-fx-background-color: BEIGE;");       
       
      //Creating a scene object 
      Scene scene = new Scene(gridPane); 
      
      //Setting title to the Stage 
      stage.setTitle("Real Time Temperature"); 
         
      //Adding scene to the stage 
      stage.setScene(scene);  
      
      //Displaying the contents of the stage 
      stage.show(); 
   }      
   public static void main(String args[]){ 
      launch(args); 
   } 
}