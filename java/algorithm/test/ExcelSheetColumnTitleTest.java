import done.ExcelSheetColumnTitle;
import org.junit.jupiter.api.Test;

import java.sql.SQLOutput;

import static org.junit.jupiter.api.Assertions.*;

class ExcelSheetColumnTitleTest {

    ExcelSheetColumnTitle solution = new ExcelSheetColumnTitle();

    @Test
    void convertToTitle() {
        assertEquals("A", solution.convertToTitle(1));
        assertEquals("Z", solution.convertToTitle(26));
        assertEquals("AB", solution.convertToTitle(28));
        assertEquals("ZY", solution.convertToTitle(701));
    }

    @Test
    void convertToTitle1() {
        assertEquals("A", solution.convertToTitle_1(1));
        assertEquals("Z", solution.convertToTitle_1(26));
        assertEquals("AB", solution.convertToTitle_1(28));
        assertEquals("ZY", solution.convertToTitle_1(701));
    }

}
