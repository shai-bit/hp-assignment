#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/json_parser.hpp>

void list_files(const boost::filesystem::path& directory, boost::property_tree::ptree& pt) {
    boost::filesystem::directory_iterator end_itr;

    // Creamos el nodo que contendra a los hijos
    boost::property_tree::ptree& files_node = pt.add_child("files", boost::property_tree::ptree());

    // Iteramos sobre todos los archivos en la dirección especificada
    for (boost::filesystem::directory_iterator itr(directory); itr != end_itr; ++itr) {
        if (boost::filesystem::is_regular_file(itr->status())) {
            boost::uintmax_t file_size = boost::filesystem::file_size(itr->path());

            // Agregamos uno nuevo
            boost::property_tree::ptree file_node;
            file_node.put("name", itr->path().filename().string());
            file_node.put("size", file_size);
            files_node.push_back(std::make_pair("", file_node));
        }
    }
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>\n";
        return 1;
    }

    // Obtenemos la dirección
    boost::filesystem::path directory(argv[1]);

    // Aquí guardaremos los nombre y tamaños
    boost::property_tree::ptree pt;

    list_files(directory, pt);

    // Creamos el JSON
    boost::property_tree::write_json("dir.json", pt);

    std::cout << "dir.json created successfully.\n";
    return 0;
}
