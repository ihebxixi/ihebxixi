/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *xixi_menu;
  GtkWidget *xixi_ajouter;
  GtkWidget *xixi_modifier;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  xixi_menu = create_xixi_menu ();
  gtk_widget_show (xixi_menu);
  /*xixi_ajouter = create_xixi_ajouter ();
  gtk_widget_show (xixi_ajouter);
  xixi_modifier = create_xixi_modifier ();
  gtk_widget_show (xixi_modifier);
*/
  gtk_main ();
  return 0;
}
