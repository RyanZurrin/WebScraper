#include "ScraperUtilities.h"


int main()
{
    std::string page_content = extract_html_page();
    GumboOutput* parsed_response = gumbo_parse(page_content.c_str());

    search_for_title(parsed_response->root);
    writeCsv << "type,link" << "\n";
    search_for_links(parsed_response->root);
    writeCsv.close();
    // free the allocated memory
    gumbo_destroy_output(&kGumboDefaultOptions, parsed_response);
}
