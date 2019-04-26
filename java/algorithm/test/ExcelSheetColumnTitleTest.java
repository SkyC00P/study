import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ExcelSheetColumnTitleTest {

    ExcelSheetColumnTitle solution = new ExcelSheetColumnTitle();

    @Test
    void convertToTitle() {
        assertEquals("A", solution.convertToTitle(1));
        assertEquals("AB", solution.convertToTitle(28));
        assertEquals("ZY", solution.convertToTitle(701));
    }
}