import java.util.*;
/*
We are working on a batch image processing pipeline. We want to be able to list
the operations to be applied on all the images (and their parameters) in a
config file.
The idea is to load the config file, create the pipeline, and process all the
images through the pipeline. We have access to a library for image manipulation
(in the ImgLib namespace below) that has all the functions that we need for
those operations.
 
How would you design such a pipeline?
*/
 
 
public class Zoox {
    // valid inputs? modify images? Load in memory?
    public void process(List<String> operations, List<Image> imgs) {
        // build operations
        List<ImageOperation> imageOperations = new ArrayList<>();
        for (String op: operations) {
            List<String> params = new ArrayList<>();
            String name = parseOperation(op, params);
            imageOperations.add(ImageOperationFactory.getOperation(name, params));
        }
        // process images
        for (Image img: imgs) {
            for(ImageOperation op: imageOperations) {
                op.execute(img);
            }
        }
    }
 
    private String parseOperation(String op, List<String> params) {
        String[] parts = op.split(" ");
        for (int i = 1; i < parts.length; i++) {
            params.add(parts[i]);
        }
        return parts[0];
    }
 
}
 
class ImageOperationFactory {
    public static ImageOperation getOperation(String name, List<String> params) {
        if ("blur".equalsIgnoreCase(name)) {
            return new BlurOperation(params);
        } else {
            return null;
        }
    }
}
 
abstract class ImageOperation {
    public void execute(Image img) {
    }
 
    protected float parseFloat(String s) {
        return Float.valueOf(s);
    }
}
 
class BlurOperation extends ImageOperation {
    private float factor;
 
    public BlurOperation(List<String> params) {
        factor = parseFloat(params.get(0));
    }
 
    @Override
    public void execute(Image img) {
        new ImgLib().blur(img, factor);
    }
}
 
// Do not modify.
class Image {
    private String name;
    public Image (String n) {
        n = name;
    }
}
 
// Do not modify.
class ImgLib {
    void convertToGrayScale (Image img) {
    }
 
    void blur (Image img, float factor) {
    }
 
    void resize (Image img, int x, int y) {
    }
 
    void blend (Image img, Image other) {
    }
}