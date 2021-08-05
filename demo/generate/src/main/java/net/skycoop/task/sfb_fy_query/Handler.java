package net.skycoop.task.sfb_fy_query;

import net.skycoop.Tool;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import java.util.*;

public class Handler extends DefaultHandler {
    private List<FyRyxx> fyRyxxes = new ArrayList<>();
    private int count;
    private FyRyxx ryxx;
    private Stack<String> stack = new Stack<>();
    private Set<String> ignores = new HashSet<>();

    @Override
    public void startDocument() {
        ignores.add("resource");
        ignores.add("brief");
        ignores.add("data");
        ignores.add("T_AJ_FZJL");
        ignores.add("T_XS_DSRGZDZLXXX_FZJL");
    }

    public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
        if (ignores.contains(qName)) return;
        if (Objects.equals("T_AJ_DSR_FZJL", qName)) {
            ryxx = new FyRyxx();
        }
        stack.push(qName);
    }

    public void endElement(String uri, String localName, String qName) {
        if (ignores.contains(qName)) return;
        if (Objects.equals("T_AJ_DSR_FZJL", qName)) {
            initFyxx();
            fyRyxxes.add(ryxx);
        } else if (Objects.equals("count", qName)) {
            String _count = stack.pop();
            if (Tool.isNotBlank(_count) && Tool.isNumber(_count)) {
                count = Integer.parseInt(_count);
            }
            while (Objects.equals("count", _count)) {
                _count = stack.pop();
            }
        } else {
            stack.push(qName);
        }
    }

    private void initFyxx() {
        String s_node = stack.pop();
        while (!Objects.equals(s_node, "T_AJ_DSR_FZJL")) {
            switch (s_node) {
                case "C_MC":
                    ryxx.setC_mc(stack.pop());
                    stack.pop();
                    break;
                case "C_ZJHM":
                    ryxx.setC_zjhm(stack.pop());
                    stack.pop();
                    break;
                case "D_CSRQ":
                    ryxx.setD_csrq(stack.pop());
                    stack.pop();
                    break;
                case "N_XB":
                    ryxx.setN_xb(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_MZ":
                    ryxx.setN_mz(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_WHCD":
                    ryxx.setN_whcd(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "C_XZZ":
                    ryxx.setC_xzz(stack.pop());
                    stack.pop();
                    break;
                case "N_DZZM":
                    ryxx.setN_dzzm(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_GTFZ":
                    ryxx.setN_gtfz(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_PCJG":
                    ryxx.setN_pcjg(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_SYZXZL":
                    ryxx.setN_syzxzl(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "C_SYFJXZL":
                    ryxx.setC_syfjxzl(stack.pop());
                    stack.pop();
                    break;
                case "N_ZYXXQN":
                    ryxx.setN_zyxxqn(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_ZYXXQY":
                    ryxx.setN_zyxxqy(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_ZYXXQR":
                    ryxx.setN_zyxxqr(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_FJXSYFS":
                    ryxx.setN_fjxsyfs(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_ZFLX":
                    ryxx.setN_zflx(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "C_AH":
                    ryxx.setC_ah(stack.pop());
                    stack.pop();
                    break;
                case "N_BH_JBFY":
                    ryxx.setN_bh_jbfy(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_HYZK":
                    ryxx.setN_hyzk(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                case "N_GTFZDW":
                    ryxx.setN_gtfzdw(Integer.parseInt(stack.pop()));
                    stack.pop();
                    break;
                default:
                    System.out.println("Unknown node:" + s_node);
            }
            s_node = stack.pop();
        }
    }

    public List<FyRyxx> getFyRyxxes() {
        return fyRyxxes;
    }

    public int getCount() {
        return count;
    }

    public void characters(char[] ch, int start, int length) {
        String txt = new String(ch, start, length);
        if (Tool.isNotBlank(txt)) {
            stack.push(txt);
        }
    }
}
