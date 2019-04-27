import org.junit.jupiter.api.Test;

import java.sql.SQLOutput;

import static org.junit.jupiter.api.Assertions.*;

class ExcelSheetColumnTitleTest {

    ExcelSheetColumnTitle solution = new ExcelSheetColumnTitle();
    final char[] excelSheet = new char[]{
            'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
            'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y'
    };

    @Test
    void convertToTitle() {
        assertEquals("A", solution.convertToTitle(1));
        assertEquals("AB", solution.convertToTitle(28));
        assertEquals("ZY", solution.convertToTitle(701));
    }

    @Test
    void test() {
        for (int i = 1; i <= excelSheet.length; i++) {
            System.out.println(String.format("i:%d,char:%s", i, excelSheet[i % 26]));
            assertEquals('A' + i - 1, excelSheet[i % 26]);
        }
        showDivisorAndRemainder(701, 26);
        showDivisorAndRemainder(26, 26);

        showDivisorAndRemainder(28, 26);
        showDivisorAndRemainder(1, 26);

        showDivisorAndRemainder(52, 26);
        showDivisorAndRemainder(2, 26);

        System.out.println("16进制");
        for (int i = 32; i >= 0; i--) {
            showDivisorAndRemainder(i, 16);
        }
    }

    private void showDivisorAndRemainder(int num, int scale) {
        System.out.println(String.format("num:%d,Divisor:%d,Remainder:%d", num, num / scale, num % scale));
    }
}