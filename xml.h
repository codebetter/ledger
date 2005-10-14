#ifndef _XML_H
#define _XML_H

#include "parser.h"
#include "format.h"

namespace ledger {

class xml_parser_t : public parser_t
{
 public:
  virtual bool test(std::istream& in) const;

  virtual unsigned int parse(std::istream&	 in,
			     journal_t *	 journal,
			     account_t *	 master        = NULL,
			     const std::string * original_file = NULL);
};

class format_xml_entries : public format_entries
{
  bool show_totals;
 public:
  format_xml_entries(std::ostream& output_stream,
		     const bool _show_totals = false)
    : format_entries(output_stream, ""), show_totals(_show_totals) {
    output_stream << "<?xml version=\"1.0\"?>\n"
		  << "<ledger version=\"2.5\">\n";
  }

  virtual void flush() {
    format_entries::flush();
    output_stream << "</ledger>" << std::endl;
  }

  virtual void format_last_entry();
};

} // namespace ledger

#endif // _XML_H
