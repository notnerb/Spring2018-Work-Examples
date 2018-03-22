
import java.io.*;
import java.util.Vector;

//"rename *. *.txt" can be used in windows command line (without the quotes) to quickly rename all the storm_traj files to the txt format required by the reader.
public class FileReader {


    public static void main(String args[]){
        String filePath = "StormData/traj_1984.txt";
        String outFilePath = "StormData/DomainStorms.rtf";
        String delemiter = "\\s+";
        double[][] domain = {{-81, 25},{-81,27},{-79, 27},{-79,25}};
        readFile(filePath, delemiter, outFilePath, domain);

    }
    //make domain a class.
    /*public void setDomain(double[] p1, double[] p2, double [] p3, double [] p4){
        domain[0] = p1;
        domain[1] = p2;
        domain[2] = p3;
        domain[3] = p4;
    }*/

    public static void setFileFormat(String fileFormat1){

    }

    public static void setDelimiter(char delimiter1){

    }
    //consider passing this a premade file writer, since mutliple files will be opened, but only a single output file may be needed.

    public static void readFile(String filePath1, String delimiter1, String outFilePath1, double[][] domain){
        java.io.FileReader fileReader = null;
        FileWriter fileWriter;
        String line = null;
        String[] parts;
        String recordHeader;
        Vector<String> recordBuffer = new Vector<>();
        boolean inDomain =  false;
        try {
            fileReader = new java.io.FileReader(filePath1);
            fileWriter = new FileWriter(outFilePath1);
            BufferedWriter bw = new BufferedWriter(fileWriter);
            BufferedReader br =  new BufferedReader(fileReader);
            while ((line = br.readLine()) != null){
                //Read in header line for storm.
                parts = line.split(delimiter1);
                for(String a : parts){
                    //System.out.print(a);
                }

                //Save header for potential output;
                recordBuffer.add(line);
                //records per line
                int numRecords = Integer.parseInt(parts[1]);
                //inspect every record associated with that header.
                for(int i = 0
                    ; i < numRecords; i++){
                    line = br.readLine();
                    recordBuffer.add(line);
                    parts = line.split(delimiter1);

                    double lon = Double.parseDouble(parts[2]);
                    double lat = (360 - Double.parseDouble(parts[1]))*-1;
                    //System.out.print(lat);
                    //System.out.print(lon);
                    //System.out.print("\n");
                    double [] pnt = {lat,lon};


                    if(RayCasting.contains(domain, pnt))
                    {
                        System.out.print(recordBuffer.get(0) + "\n");
                        inDomain = true;
                    }
                }

                if(inDomain){
                    for(int i = 0; i<recordBuffer.size();i++){
                        bw.write(recordBuffer.get(i));
                        bw.newLine();
                    }
                    inDomain = false;

                }
                recordBuffer.clear();
            }
            //free resources
            recordBuffer.clear();
            fileReader.close();
            bw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }




}
