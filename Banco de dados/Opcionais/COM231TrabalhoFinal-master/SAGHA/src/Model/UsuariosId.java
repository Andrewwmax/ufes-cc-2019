package Model;
// Generated 08/06/2017 15:34:03 by Hibernate Tools 4.3.1



/**
 * UsuariosId generated by hbm2java
 */
public class UsuariosId  implements java.io.Serializable {


     private String login;
     private String senha;

    public UsuariosId() {
    }

    public UsuariosId(String login, String senha) {
       this.login = login;
       this.senha = senha;
    }
   
    public String getLogin() {
        return this.login;
    }
    
    public void setLogin(String login) {
        this.login = login;
    }
    public String getSenha() {
        return this.senha;
    }
    
    public void setSenha(String senha) {
        this.senha = senha;
    }


   public boolean equals(Object other) {
         if ( (this == other ) ) return true;
		 if ( (other == null ) ) return false;
		 if ( !(other instanceof UsuariosId) ) return false;
		 UsuariosId castOther = ( UsuariosId ) other; 
         
		 return ( (this.getLogin()==castOther.getLogin()) || ( this.getLogin()!=null && castOther.getLogin()!=null && this.getLogin().equals(castOther.getLogin()) ) )
 && ( (this.getSenha()==castOther.getSenha()) || ( this.getSenha()!=null && castOther.getSenha()!=null && this.getSenha().equals(castOther.getSenha()) ) );
   }
   
   public int hashCode() {
         int result = 17;
         
         result = 37 * result + ( getLogin() == null ? 0 : this.getLogin().hashCode() );
         result = 37 * result + ( getSenha() == null ? 0 : this.getSenha().hashCode() );
         return result;
   }   


}


