import java.util.Stack;
import java.util.HashSet;
/**
 * CS 420
 * Homework 5
 * Cameron Stark
 * 
 * Implements FIFO paging algorithm
 */
public class FIFO extends ReplacementAlgorithm {

    public Stack<Integer> referenceStack;
    public HashSet<Integer> pageFrames;

    public FIFO(int pageFrameCount) {
        super(pageFrameCount);

        pageFrames = new HashSet<>();
        referenceStack = new Stack<Integer>();
    }

    @Override
    public void insert(int number) {
        if (pageFrames.contains(number)) {
            referenceStack.push(number);
        } else {
            pageFaultCount++;
            if (pageFrames.size() == pageFrameCount) {
                pageFrames.remove(referenceStack.pop());
            }

            pageFrames.add(number);
        }
    }
}