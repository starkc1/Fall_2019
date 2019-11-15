import java.util.Stack;
import java.util.HashSet;
/**
 * CS 420
 * Homework 5
 * Cameron Stark
 * 
 * Implements LRU paging algorithm
 * 
 */
public class LRU extends ReplacementAlgorithm {

    public HashSet<Integer> pageFrames;
    public Stack<Integer> referenceStack;

    public LRU(int pageFrameCount) {
        super(pageFrameCount);

        pageFrames = new HashSet<>();
        referenceStack = new Stack<>();
    }

    @Override
    public void insert(int number) {
        referenceStack.removeElement(number);

        if (pageFrames.contains(number)) {
            referenceStack.push(number);
        } else {
            pageFaultCount++;
            if (pageFrames.size() == pageFrameCount) {
                for (int i = 0; i < referenceStack.size(); i++) {
                    if (pageFrames.contains(referenceStack.elementAt(i))) {
                        pageFrames.remove(referenceStack.elementAt(i));
                        break;
                    }
                }
            }
            pageFrames.add(number);
        }
    }

}