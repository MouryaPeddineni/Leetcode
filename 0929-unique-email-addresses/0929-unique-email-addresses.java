class Solution {

    public int numUniqueEmails(String[] emails) {
        int i = 0;
        String localname, domainname, mail;
        Set<String> mailidlist = new HashSet<String>();
        while (i < emails.length) {
            localname = emails[i].substring(0,emails[i].indexOf('@'));
            int len = localname.length();
            if(localname.contains(".") && localname.indexOf('.') < len){
                localname = localname.replace(".","");
            }
            if(localname.contains("+") && localname.indexOf('+') < len){
                localname = localname.substring(0,localname.indexOf('+'));
            }
            domainname = emails[i].substring(emails[i].indexOf('@') + 1);
            mail = localname + "@" + domainname;
            mailidlist.add(mail);
            i++;
        }
        return mailidlist.size();
    }
}