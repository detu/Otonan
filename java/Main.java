import java.text.SimpleDateFormat;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        SakaCalendar tanggal = new SakaCalendar(2023,3,3);

        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-yyyy");

        System.out.println("Tanggal " + sdf.format(tanggal.getTime()));

        System.out.println("No Wuku " + tanggal.getWuku(SakaCalendar.NO_WUKU));

        System.out.println("No Pancawara " + tanggal.getPancawara(SakaCalendar.NO_PANCAWARA));

        System.out.println("No Saptawara " + tanggal.getSaptawara(SakaCalendar.NO_SAPTAWARA));

        System.out.println("Tahun Saka " + tanggal.getSakaCalendar(SakaCalendar.TAHUN_SAKA));
        System.out.println("No Sasih " + tanggal.getSakaCalendar(SakaCalendar.NO_SASIH));
        System.out.println("Penanggal " + tanggal.getSakaCalendar(SakaCalendar.PENANGGAL));
        System.out.println((tanggal.getSakaCalendarStatus(SakaCalendar.IS_PANGELONG)) ? "Pangelong" : "Penanggal");
        System.out.println((tanggal.getSakaCalendarStatus(SakaCalendar.IS_NGUNARATRI)) ? "Ngunaratri" : "Bukan ngunaratri");
        System.out.println((tanggal.getSakaCalendarStatus(SakaCalendar.IS_NAMPIH)) ? "Nampih sasih" : "Bukan nampih sasih");

    }
}
