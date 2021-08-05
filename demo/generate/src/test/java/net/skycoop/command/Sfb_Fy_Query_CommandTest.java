package net.skycoop.command;


import net.skycoop.task.sfb_fy_query.FyRyxx;
import net.skycoop.task.sfb_fy_query.Handler;
import org.junit.Test;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.File;

public class Sfb_Fy_Query_CommandTest {

    final static File FILE = new File("D:\\project\\study\\demo\\generate\\src\\test\\resources\\test.xml");

    @Test
    public void xmlParse() {
        try {
            JAXBContext jaxbContext = JAXBContext.newInstance(FyRyxx.class);
            Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
            FyRyxx fyRyxx = (FyRyxx) unmarshaller.unmarshal(FILE);
            System.out.println(fyRyxx);
        } catch (JAXBException e) {
            e.printStackTrace();
        }
    }
    @Test
    public void xmlParse_SAX() throws Throwable {
        SAXParserFactory spf = SAXParserFactory.newInstance();
        SAXParser saxParser = spf.newSAXParser();
        Handler handler = new Handler();
        saxParser.parse(FILE, handler);
//        System.out.println(handler.count);
//        System.out.println(handler.fyRyxxes.size());
//        for (FyRyxx r : handler.fyRyxxes) {
//            System.out.println(r);
//        }
    }
}
