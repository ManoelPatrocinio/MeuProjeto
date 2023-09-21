#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DataHora
{
    int Dia, Mes, Ano;
    float hora;
};

struct Cliente
{
    string CPF;
    string Nome;
    DataHora DtNascimento;
    string CNH;

    void incluirCliente(Cliente *clienteDados)
    {

        system("clear");
        cout << "Digite o nome do cliente: ";
        getline(cin, clienteDados->Nome);
        cout << "Digite o CPF do cliente: ";
        getline(cin, clienteDados->CPF);
        cout << "Digite a CNH do cliente: ";
        getline(cin, clienteDados->CNH);

        do
        {
            cout << "Digite o Dia de nascimento do cliente: ";
            cin >> clienteDados->DtNascimento.Dia;

        } while (clienteDados->DtNascimento.Dia <= 0 || clienteDados->DtNascimento.Dia > 31);

        do
        {
            cout << "Digite o Mes de nascimento do cliente: ";
            cin >> clienteDados->DtNascimento.Mes;
        } while (clienteDados->DtNascimento.Mes <= 0 || clienteDados->DtNascimento.Mes > 12);

        do
        {
            cout << "Digite o Ano de nascimento do cliente: ";
            cin >> clienteDados->DtNascimento.Ano;
            cin.ignore();
        } while (clienteDados->DtNascimento.Ano < 1900 || clienteDados->DtNascimento.Ano > 3000);

        cout << endl;
        cout << "Cliente cadastrado com sucesso!";
        cout << endl;
        cout << endl;
    };

    void listarClientes(vector<Cliente> &listaClientes)
    {

        system("clear");

        if (listaClientes.size() <= 0)
        {
            cout << endl;
            cout << endl;
            cout << "--- Não há Clientes Cadastrados --- " << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << endl;
            cout << "--- Clientes Cadastrados --- " << endl;
            cout << endl;

            for (auto &cliente : listaClientes)
            {

                cout << "Nome do cliente: " << cliente.Nome << endl;
                cout << "CPF do cliente: " << cliente.CPF << endl;
                cout << "CNH do cliente: " << cliente.CNH << endl;
                cout << "Data de nascimento: " << cliente.DtNascimento.Dia << "/" << cliente.DtNascimento.Mes << "/" << cliente.DtNascimento.Ano << endl;
                cout << endl;
            }
        }

        cout << endl;
        cout << endl;
    };

    void excluirCliente(vector<Cliente> &listaClientes)
    {

        string cpfDeExclusao;
        int cont = -1;

        system("clear");

        cout << "Digite o CPF do cliente que deseja excluir: ";
        getline(cin, cpfDeExclusao);

        vector<Cliente>::iterator i;
        i = listaClientes.begin();

        for (auto &cliente : listaClientes)
        {
            cont += 1;
            if (cpfDeExclusao == cliente.CPF)
            {

                advance(i, cont);
                listaClientes.erase(i);
                cout << "Excluído com sucesso !" << endl;
            }
        }
    };

    void localizaCliente(vector<Cliente> &listaClientes)
    {

        string cpfDeBusca;

        system("clear");

        cout << "Digite o CPF do cliente que deseja buscar: ";
        getline(cin, cpfDeBusca);

        for (auto &cliente : listaClientes)
        {
            if (cpfDeBusca == cliente.CPF)
            {
                cout << endl;
                cout << "--- Cliente Encontrado ---" << endl;
                cout << endl;
                cout << "Nome do cliente: " << cliente.Nome << endl;
                cout << "CPF do cliente: " << cliente.CPF << endl;
                cout << "CNH do cliente: " << cliente.CNH << endl;
                cout << "Data de nascimento: " << cliente.DtNascimento.Dia << "/" << cliente.DtNascimento.Mes << "/" << cliente.DtNascimento.Ano << endl;
                cout << endl;
            }
        }
    };

    int menuAlteracaoClente()
    {
        int escolha;
        do
        {
            system("clear");

            cout << endl;
            cout << endl;

            cout << "Digite  1 - p/ alterar o nome do cliente: " << endl;
            cout << "Digite  2 - p/ alterar o CPF do cliente: " << endl;
            cout << "Digite  3 - p/ alterar o Dia de nascimento do cliente: " << endl;
            cout << "Digite  4 - p/ alterar o Mes de nascimento do cliente: " << endl;
            cout << "Digite  5 - p/ alterar o Ano de nascimento do cliente: " << endl;
            cout << "Digite  6 - p/ alterar a CNH do cliente: " << endl;
            cout << "Sua escolha: ";
            cin >> escolha;
            cin.ignore();

        } while (escolha < 1 || escolha > 6);

        return escolha;
    }

    void alterarCliente(vector<Cliente> &listaClientes)
    {

        Cliente clienteNovosDados;
        string cpfDeAlteracao;
        int cont = -1, escolha, menuOpcao;

        system("clear");

        cout << "Digite o CPF do cliente que deseja altera os dados: ";
        getline(cin, cpfDeAlteracao);

        vector<Cliente>::iterator i;
        i = listaClientes.begin();

        for (auto &cliente : listaClientes)
        {
            cont += 1;
            if (cpfDeAlteracao == cliente.CPF)
            {

                cout << endl;
                cout << "--- Cliente Encontrado ---" << endl;
                cout << endl;
                cout << "Nome do cliente: " << cliente.Nome << endl;
                cout << "CPF do cliente: " << cliente.CPF << endl;
                cout << "CNH do cliente: " << cliente.CNH << endl;
                cout << "Data de nascimento: " << cliente.DtNascimento.Dia << "/" << cliente.DtNascimento.Mes << "/" << cliente.DtNascimento.Ano << endl;
                cout << endl;

                do
                {

                    cout << "Deseja alterar os dados desse cliente ? " << endl;
                    cout << " Digite 1 - P/ Sim | Digite 2 - P/ Nao" << endl;
                    cout << "Sua escolha: ";
                    cin >> escolha;

                    if (escolha == 1)
                    {
                        menuOpcao = menuAlteracaoClente();

                        switch (menuOpcao)
                        {
                        case 1:
                            cout << "Informe o novo nome para o cliente: ";
                            getline(cin, clienteNovosDados.Nome);

                            advance(i, cont);

                            i->Nome = clienteNovosDados.Nome;
                            break;
                        case 2:
                            cout << "Informe o novo CPF para o cliente: ";
                            getline(cin, clienteNovosDados.CPF);

                            advance(i, cont);

                            i->CPF = clienteNovosDados.CPF;
                            break;
                        case 3:
                            cout << "Informe o novo Dia de  nascimento do cliente: ";
                            cin >> clienteNovosDados.DtNascimento.Dia;

                            advance(i, cont);

                            i->DtNascimento.Dia = clienteNovosDados.DtNascimento.Dia;
                            break;
                        case 4:
                            cout << "Informe o novo Mes de  nascimento do cliente: ";
                            cin >> clienteNovosDados.DtNascimento.Mes;

                            advance(i, cont);

                            i->DtNascimento.Mes = clienteNovosDados.DtNascimento.Mes;
                            break;
                        case 5:
                            cout << "Informe o novo Ano de  nascimento do cliente: ";
                            cin >> clienteNovosDados.DtNascimento.Ano;

                            advance(i, cont);

                            i->DtNascimento.Ano = clienteNovosDados.DtNascimento.Ano;
                            break;
                        case 6:
                            cin.ignore();
                            cout << "Informe o novo CNH para o cliente: ";
                            getline(cin, clienteNovosDados.CNH);

                            advance(i, cont);

                            i->CNH = clienteNovosDados.CNH;
                            break;

                        default:
                            break;
                        }
                    }
                } while (escolha != 2);
            }
        }
    };

    int menu_cliente(void)
    {
        int escolha;
        do
        {
            cout << "--- Gestão de Clientes --- " << endl;
            cout << endl;

            cout << "1 - p/ Incluir cliente" << endl;
            cout << "2 - p/ Excluir um cliente" << endl;
            cout << "3 - p/ Alterar um cliente" << endl;
            cout << "4 - p/ Listar clientes" << endl;
            cout << "5 - p/ Localizar Cliente" << endl;
            cout << "0 - p/ Sair " << endl;
            cout << "Sua escolha: ";
            cin >> escolha;
            cin.ignore();

        } while (escolha < 0 || escolha > 5);

        return escolha;
    }
};

struct Veiculo
{
    string Renavan;
    string Placa_do_Veiculo;
    DataHora Data_Hora_Retirada;
    DataHora Data_Hora_Entrega;
    string Loja_Retirada;

    void incluirVeiculo(Veiculo *veiculoDados)
    {

        system("clear");
        cout << "Digite o renavan do Veiculo: ";
        getline(cin, veiculoDados->Renavan);
        cout << "Digite  a placa do Veiculo: ";
        getline(cin, veiculoDados->Placa_do_Veiculo);

        cout << endl;
        cout << endl;
        cout << "Dados da Retirada do veículo" << endl
             << endl;
        cout << "Digite o nome da loja de retirada: ";
        getline(cin, veiculoDados->Loja_Retirada);

        do
        {
            cout << "Digite o Dia de retirada do veiculo: ";
            cin >> veiculoDados->Data_Hora_Retirada.Dia;
        } while (veiculoDados->Data_Hora_Retirada.Dia <= 0 || veiculoDados->Data_Hora_Retirada.Dia > 31);

        do
        {
            cout << "Digite o Mes de retirada do veiculo: ";
            cin >> veiculoDados->Data_Hora_Retirada.Mes;
        } while (veiculoDados->Data_Hora_Retirada.Mes <= 0 || veiculoDados->Data_Hora_Retirada.Mes > 12);

        do
        {
            cout << "Digite o Ano de retirada do veiculo: ";
            cin >> veiculoDados->Data_Hora_Retirada.Ano;
        } while (veiculoDados->Data_Hora_Retirada.Ano < 1900 || veiculoDados->Data_Hora_Retirada.Ano > 3000);

        do
        {
            cout << "Digite a Hora/minuto de retirada do veiculo(ex: 10.30 ou 18.15): ";
            cin >> veiculoDados->Data_Hora_Retirada.hora;
        } while (veiculoDados->Data_Hora_Retirada.hora <= 0 || veiculoDados->Data_Hora_Retirada.hora > 24);

        cout << endl;
        cout << endl;
        cout << "Dados da Entrega do veículo" << endl
             << endl;

        do
        {
            cout << "Digite o Dia da entrega do veiculo: ";
            cin >> veiculoDados->Data_Hora_Entrega.Dia;
        } while (veiculoDados->Data_Hora_Entrega.Dia <= 0 || veiculoDados->Data_Hora_Entrega.Dia > 31);

        do
        {
            cout << "Digite o Mes da entrega do veiculo: ";
            cin >> veiculoDados->Data_Hora_Entrega.Mes;
        } while (veiculoDados->Data_Hora_Entrega.Mes <= 0 || veiculoDados->Data_Hora_Entrega.Mes > 12);

        do
        {
            cout << "Digite o Ano da entrega do veiculo: ";
            cin >> veiculoDados->Data_Hora_Entrega.Ano;
        } while (veiculoDados->Data_Hora_Entrega.Ano < 1900 || veiculoDados->Data_Hora_Entrega.Ano > 3000);

        do
        {
            cout << "Digite a Hora/minuto da entrega do veiculo(ex: 10.30 ou 18.15) : ";
            cin >> veiculoDados->Data_Hora_Entrega.hora;
            cin.ignore();
        } while (veiculoDados->Data_Hora_Entrega.hora < 0 || veiculoDados->Data_Hora_Entrega.hora > 24);

        cout << endl;
        cout << "Veículo cadastrado com sucesso!";
        cout << endl;
        cout << endl;
    };

    void listarVeiculos(vector<Veiculo> &listaVeiculos)
    {

        system("clear");

        if (listaVeiculos.size() <= 0)
        {
            cout << endl;
            cout << endl;
            cout << "--- Não há Veiculos Cadastrados --- " << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << endl;
            cout << "--- Veiculos Cadastrados --- " << endl;
            cout << endl;

            for (auto &veiculo : listaVeiculos)
            {

                cout << "Renavan do veiculo: " << veiculo.Renavan << endl;
                cout << "Placa do veiculo: " << veiculo.Placa_do_Veiculo << endl;

                cout << endl;
                cout << "Dados da Retirada do veículo" << endl
                     << endl;
                cout << "Loja de retirada: " << veiculo.Loja_Retirada << endl;
                cout << "Data de retirada: " << veiculo.Data_Hora_Retirada.Dia << "/" << veiculo.Data_Hora_Retirada.Mes << "/" << veiculo.Data_Hora_Retirada.Ano << endl;
                cout << endl;
                cout << "Dados da Entrega do veículo" << endl
                     << endl;
                cout << "Data de retirada: " << veiculo.Data_Hora_Entrega.Dia << "/" << veiculo.Data_Hora_Entrega.Mes << "/" << veiculo.Data_Hora_Entrega.Ano << endl;
                cout << endl;
            }
        }

        cout << endl;
        cout << endl;
    };

    void excluirVeiculo(vector<Veiculo> &listaVeiculos)
    {

        string placaDeExclusao;
        int cont = -1;

        system("clear");

        cout << "Digite a placa do veiculo que deseja excluir: ";
        getline(cin, placaDeExclusao);

        vector<Veiculo>::iterator i;
        i = listaVeiculos.begin();

        for (auto &veiculo : listaVeiculos)
        {
            cont += 1;
            if (placaDeExclusao == veiculo.Placa_do_Veiculo)
            {

                advance(i, cont);
                listaVeiculos.erase(i);
                cout << "Excluído com sucesso !" << endl;
            }
        }
    };

    void localizaVeiculo(vector<Veiculo> &listaVeiculos)
    {

        string placaDeBusca;

        system("clear");

        cout << "Digite a placa do veiculo que deseja buscar: ";
        getline(cin, placaDeBusca);

        for (auto &veiculo : listaVeiculos)
        {
            if (placaDeBusca == veiculo.Placa_do_Veiculo)
            {
                cout << "Renavan do veiculo: " << veiculo.Renavan << endl;
                cout << "Placa do veiculo: " << veiculo.Placa_do_Veiculo << endl;

                cout << endl;
                cout << "Dados da Retirada do veículo" << endl
                     << endl;
                cout << "Loja de retirada: " << veiculo.Loja_Retirada << endl;
                cout << "Data de retirada: " << veiculo.Data_Hora_Retirada.Dia << "/" << veiculo.Data_Hora_Retirada.Mes << "/" << veiculo.Data_Hora_Retirada.Ano << endl;
                cout << endl;
                cout << "Dados da Entrega do veículo" << endl
                     << endl;
                cout << "Data de retirada: " << veiculo.Data_Hora_Entrega.Dia << "/" << veiculo.Data_Hora_Entrega.Mes << "/" << veiculo.Data_Hora_Entrega.Ano << endl;
                cout << endl;
            }
        }
    };

    int menuAlteracaoVeiculo()
    {
        int escolha;
        do
        {
            system("clear");

            cout << endl;
            cout << endl;

            cout << "Digite  1 - p/ alterar o renavan: " << endl;
            cout << "Digite  2 - p/ alterar  a placa: " << endl;

            cout << "Digite  3 - p/ alterar a loja de retira: " << endl;
            cout << "Digite  4 - p/ alterar o dia de retirada: " << endl;
            cout << "Digite  5 - p/ alterar o Mes de retirada: " << endl;
            cout << "Digite  6 - p/ alterar o Ano de retirada: " << endl
                 << endl;
            cout << "Digite  7 - p/ alterar a hora retirada: " << endl
                 << endl;

            cout << "Digite  8 - p/ alterar o dia de entrega: " << endl;
            cout << "Digite  9 - p/ alterar o Mes de entrega: " << endl;
            cout << "Digite  10 - p/ alterar o Ano de entrega: " << endl;
            cout << "Digite  11 - p/ alterar a hora entrega: " << endl
                 << endl;

            cout << "Sua escolha: ";
            cin >> escolha;
            cin.ignore();

        } while (escolha < 1 || escolha > 11);

        return escolha;
    }

    void alterarVeiculo(vector<Veiculo> &listaVeiculos)
    {

        Veiculo veiculoNovosDados;
        string placaDeAlteracao;
        int cont = -1, escolha, menuOpcao;

        system("clear");

        cout << "Digite a placa que deseja altera os dados: ";
        getline(cin, placaDeAlteracao);

        vector<Veiculo>::iterator i;
        i = listaVeiculos.begin();

        for (auto &veiculo : listaVeiculos)
        {
            cont += 1;
            if (placaDeAlteracao == veiculo.Placa_do_Veiculo)
            {

                cout << "Renavan do veiculo: " << veiculo.Renavan << endl;
                cout << "Placa do veiculo: " << veiculo.Placa_do_Veiculo << endl;

                cout << endl;
                cout << "Dados da Retirada do veículo" << endl
                     << endl;
                cout << "Loja de retirada: " << veiculo.Loja_Retirada << endl;
                cout << "Data de retirada: " << veiculo.Data_Hora_Retirada.Dia << "/" << veiculo.Data_Hora_Retirada.Mes << "/" << veiculo.Data_Hora_Retirada.Ano << endl;
                cout << endl;
                cout << "Dados da Entrega do veículo" << endl
                     << endl;
                cout << "Data de entrega: " << veiculo.Data_Hora_Entrega.Dia << "/" << veiculo.Data_Hora_Entrega.Mes << "/" << veiculo.Data_Hora_Entrega.Ano << endl;
                cout << endl;

                do
                {

                    cout << "Deseja alterar os dados desse veiculo ? " << endl;
                    cout << " Digite 1 - P/ Sim | Digite 2 - P/ Nao" << endl;
                    cout << "Sua escolha: ";
                    cin >> escolha;

                    if (escolha == 1)
                    {
                        menuOpcao = menuAlteracaoVeiculo();

                        switch (menuOpcao)
                        {
                        case 1:
                            cout << "Informe o novo renavan: ";
                            getline(cin, veiculoNovosDados.Renavan);

                            advance(i, cont);

                            i->Renavan = veiculoNovosDados.Renavan;
                            break;
                        case 2:
                            cout << "Informe a nova placa do veiculo: ";
                            getline(cin, veiculoNovosDados.Placa_do_Veiculo);

                            advance(i, cont);

                            i->Placa_do_Veiculo = veiculoNovosDados.Placa_do_Veiculo;
                            break;
                        case 3:
                            cout << "Informe a nova loja de retirada do veiculo: ";
                            getline(cin, veiculoNovosDados.Loja_Retirada);

                            advance(i, cont);

                            i->Loja_Retirada = veiculoNovosDados.Loja_Retirada;
                            break;

                        case 4:
                            cout << "Informe o novo Dia retirada: ";
                            cin >> veiculoNovosDados.Data_Hora_Retirada.Dia;

                            advance(i, cont);

                            i->Data_Hora_Retirada.Dia = veiculoNovosDados.Data_Hora_Retirada.Dia;
                            break;
                        case 5:
                            cout << "Informe o novo Mes de retirada: ";
                            cin >> veiculoNovosDados.Data_Hora_Retirada.Mes;

                            advance(i, cont);

                            i->Data_Hora_Retirada.Mes = veiculoNovosDados.Data_Hora_Retirada.Mes;
                            break;
                        case 6:
                            cout << "Informe o novo Ano de  retirada: ";
                            cin >> veiculoNovosDados.Data_Hora_Retirada.Ano;

                            advance(i, cont);

                            i->Data_Hora_Retirada.Ano = veiculoNovosDados.Data_Hora_Retirada.Ano;
                            break;
                        case 7:
                            cout << "Informe o nova hora de retirada: ";
                            cin >> veiculoNovosDados.Data_Hora_Retirada.hora;

                            advance(i, cont);

                            i->Data_Hora_Retirada.hora = veiculoNovosDados.Data_Hora_Retirada.hora;
                            break;
                        case 8:
                            cout << "Informe o novo Dia entrega: ";
                            cin >> veiculoNovosDados.Data_Hora_Entrega.Dia;

                            advance(i, cont);

                            i->Data_Hora_Entrega.Dia = veiculoNovosDados.Data_Hora_Entrega.Dia;
                            break;
                        case 9:
                            cout << "Informe o novo Mes de entrega: ";
                            cin >> veiculoNovosDados.Data_Hora_Entrega.Mes;

                            advance(i, cont);

                            i->Data_Hora_Entrega.Mes = veiculoNovosDados.Data_Hora_Entrega.Mes;
                            break;
                        case 10:
                            cout << "Informe o novo Ano de  retirada: ";
                            cin >> veiculoNovosDados.Data_Hora_Entrega.Ano;

                            advance(i, cont);

                            i->Data_Hora_Entrega.Ano = veiculoNovosDados.Data_Hora_Entrega.Ano;
                            break;
                        case 11:
                            cout << "Informe a nova hora de entrega: ";
                            cin >> veiculoNovosDados.Data_Hora_Entrega.hora;

                            advance(i, cont);

                            i->Data_Hora_Entrega.hora = veiculoNovosDados.Data_Hora_Entrega.hora;
                            break;

                        default:
                            break;
                        }
                    }
                } while (escolha != 2);
            }
        }
    };

    int menu_veiculo(void)
    {
        int escolha;
        do
        {
            cout << "--- Gestão de Veículos --- " << endl;
            cout << endl;

            cout << "1 - p/ Incluir veículo" << endl;
            cout << "2 - p/ Excluir um veículo" << endl;
            cout << "3 - p/ Alterar um veículo" << endl;
            cout << "4 - p/ Listar veículos" << endl;
            cout << "5 - p/ Localizar veículo" << endl;
            cout << "0 - p/ Sair " << endl;
            cout << "Sua escolha: ";
            cin >> escolha;
            cin.ignore();

        } while (escolha < 0 || escolha > 5);

        return escolha;
    }
};

struct Locacao
{
    char realizada;
    DataHora Data_hora_retirada;
    DataHora Data_hora_entrega;
    string cliente_cnh;
    string cliente_cpf;
    string veiculo_placa;

    int verificaPlaca(vector<Veiculo> &listaDeVeiculos, string placaTempolaria)
    {
        for (auto &veiculo : listaDeVeiculos)
        {
            if (veiculo.Placa_do_Veiculo == placaTempolaria)
                return 1;
        };

        return 0;
    }

    int verificaCPF(vector<Cliente> &listaDeClientes, string cpfDeBusca)
    {
        for (auto &cliente : listaDeClientes)
        {
            if (cliente.CPF == cpfDeBusca)
                return 1;
        }

        return 0;
    }

    void incluirLocacao(Locacao *locacao, vector<Cliente> &listaDeClientes,
                        vector<Veiculo> &listaDeVeiculos)
    {
        int validacao = 0;
        string CNHTempolaria;
        char realizadaTemporaria;
        system("clear");

        cout << endl;
        cout << "--- Incluir Locação --" << endl
             << endl;

        do
        {
            cout << "Informe a CNH do cliente: ";
            getline(cin, CNHTempolaria);

            for (auto &cliente : listaDeClientes)
            {
                if (cliente.CNH == CNHTempolaria)
                {
                    if (cliente.CPF.length() <= 0)
                    {

                        cout << endl;
                        cout << endl;
                        cout << "---- Alerta ! ---" << endl;
                        cout << "O CPF deste cliente não existe !" << endl;
                        cout << "Edite este cliente e adicione um CPF válido" << endl
                             << endl;

                        return;
                    }
                    else
                    {
                        locacao->cliente_cnh = CNHTempolaria;
                        validacao = 1;
                    }
                }
            }

            if (validacao == 0)
            {
                system("clear");
                cout << endl;
                cout << endl;
                cout << "---- Alerta ! ---" << endl;
                cout << "Não existe um cliente com a CNH Informada" << endl
                     << endl;
            };

        } while (validacao != 1);

        do
        {
            cout << "Informe o CPF do cliente: ";
            getline(cin, locacao->cliente_cpf);

            if (verificaCPF(listaDeClientes, locacao->cliente_cpf) != 1)
            {
                system("clear");
                cout << endl;
                cout << endl;
                cout << "---- Alerta ! ---" << endl;
                cout << "Não existe um cliente com CPF Informado" << endl;
                cout << "Informe com CPF valido !" << endl
                     << endl;
            };
        } while (verificaCPF(listaDeClientes, locacao->cliente_cpf) != 1);

        do
        {
            cout << "Informe a placa do veiculo: ";
            getline(cin, locacao->veiculo_placa);

            if (verificaPlaca(listaDeVeiculos, locacao->veiculo_placa) != 1)
            {
                system("clear");
                cout << endl;
                cout << endl;
                cout << "---- Alerta ! ---" << endl;
                cout << "Não existe um veiculo com a placa Informada" << endl;
                cout << "Informe uma placa valida !" << endl
                     << endl;
            };
        } while (verificaPlaca(listaDeVeiculos, locacao->veiculo_placa) != 1);

        cout << endl;
        cout << "A retirada do veiculo foi realizada ?" << endl
             << "Digite: s - p/ Sim" << endl
             << "Digite: n - p/ Não" << endl;
        cout << "Sua escolha: ";
        cin >> realizadaTemporaria;

        if (realizadaTemporaria == 's' || realizadaTemporaria == 'S')
        {
            locacao->realizada = 's';
            do
            {
                cout << "Digite o Dia de retirada do veiculo: ";
                cin >> locacao->Data_hora_retirada.Dia;
            } while (locacao->Data_hora_retirada.Dia <= 0 || locacao->Data_hora_retirada.Dia > 31);

            do
            {
                cout << "Digite o Mes de retirada do veiculo: ";
                cin >> locacao->Data_hora_retirada.Mes;
            } while (locacao->Data_hora_retirada.Mes <= 0 || locacao->Data_hora_retirada.Mes > 12);

            do
            {
                cout << "Digite o Ano de retirada do veiculo: ";
                cin >> locacao->Data_hora_retirada.Ano;
            } while (locacao->Data_hora_retirada.Ano < 1900 || locacao->Data_hora_retirada.Ano > 3000);

            do
            {
                cout << "Digite a Hora/minuto de retirada do veiculo(ex: 10.30 ou 18.15): ";
                cin >> locacao->Data_hora_retirada.hora;
            } while (locacao->Data_hora_retirada.hora <= 0 || locacao->Data_hora_retirada.hora > 24);

            cout << endl
                 << endl;
            cout << " -- Locação realizada com su1cesso ! --" << endl
                 << endl;
        }
        else
        {
            locacao->realizada = 'n';
            cout << endl
                 << endl;
            cout << " -- Registro salvo com sucesso ! --" << endl
                 << endl;
        }
    }

    void excluirLocacao(vector<Locacao> &Listalocacao)
    {
        string exlocacao, verificacaoplaca;

        system("clear");

        cout << "Digite a placa de seu veiculo: " << endl;
        getline(cin, verificacaoplaca);

        cout << endl;
        cout << endl;
        cout << "--- Locaçoes cadastradas --- " << endl;
        cout << endl;
        cout << " Para o veiculo de placa: " << verificacaoplaca << "temos essas locações: " << endl;
        cout << endl;

        for (auto &locacao : Listalocacao)
        {

            if (verificacaoplaca == locacao.veiculo_placa)
            {

                cout << "CNH do cliente: " << locacao.cliente_cnh << endl;
                cout << "Data de retirada: " << locacao.Data_hora_retirada.Dia << "/" << locacao.Data_hora_retirada.Mes << "/" << locacao.Data_hora_retirada.Ano << endl;
                cout << "Hora de retirada: " << locacao.Data_hora_retirada.hora << endl;
                cout << "Data de entrega:" << locacao.Data_hora_entrega.Dia << "/" << locacao.Data_hora_entrega.Mes << "/" << locacao.Data_hora_entrega.Ano << endl;
                cout << "Hora de entrega:" << locacao.Data_hora_entrega.hora << endl;
            }
            exlocacao = verificacaoplaca;
        }

        int cont = -1;
        vector<Locacao>::iterator i;
        i = Listalocacao.begin();

        for (auto &excluirLocacao : Listalocacao)
        {
            cont += 1;
            if (exlocacao == excluirLocacao.veiculo_placa)
            {

                advance(i, cont);
                Listalocacao.erase(i);
                cout << " Excluído com sucesso !" << endl;
            }
        }
    }

    void alterarLocacao(vector<Locacao> &listaDeLocacoes, vector<Cliente> &listaDeClientes)
    {
        Locacao novosDadosLocacao;
        string cpfDeBusca;

        cout << endl;
        cout << "--- Alterar Locação --" << endl
             << endl;

        cout << "Informe a placa do veículo: ";
        getline(cin, novosDadosLocacao.veiculo_placa);

        cout << endl
             << endl
             << "--- Clientes com esse veiculo reservado ---" << endl
             << endl;

        for (auto &locacao : listaDeLocacoes)
        {
            if (locacao.veiculo_placa == novosDadosLocacao.veiculo_placa)
            {
                for (auto &cliente : listaDeClientes)
                {
                    if (cliente.CNH == locacao.cliente_cnh)
                    {
                        cout << "--- Cliente ---" << endl;
                        cout << "Nome: " << cliente.Nome << endl;
                        cout << "CPF: " << cliente.CPF << endl;
                        cout << "CNH: " << cliente.CNH << endl;
                        cout << "Data Nascimento: " << cliente.DtNascimento.Dia << "/" << cliente.DtNascimento.Mes << "/" << cliente.DtNascimento.Ano << endl;
                    }
                }
            }
        }

        do
        {
            if (listaDeLocacoes.size() > 0)
            {
                cout << "Informe o CPF do cliente que deseja alterar o registro de locação: ";
                getline(cin, cpfDeBusca);
            }

            if (verificaCPF(listaDeClientes, cpfDeBusca) == 1)
            {

                for (auto &locacao : listaDeLocacoes)
                {
                    if (locacao.cliente_cpf == cpfDeBusca)
                    {
                        do
                        {
                            cout << "Digite o Dia de entrega do veiculo: ";
                            cin >> novosDadosLocacao.Data_hora_entrega.Dia;
                            locacao.Data_hora_entrega.Dia = novosDadosLocacao.Data_hora_entrega.Dia;
                        } while (novosDadosLocacao.Data_hora_entrega.Dia <= 0 || novosDadosLocacao.Data_hora_entrega.Dia > 31);

                        do
                        {
                            cout << "Digite o Mes de entrega do veiculo: ";
                            cin >> novosDadosLocacao.Data_hora_entrega.Mes;
                            locacao.Data_hora_entrega.Mes = novosDadosLocacao.Data_hora_entrega.Mes;

                        } while (novosDadosLocacao.Data_hora_entrega.Mes <= 0 || novosDadosLocacao.Data_hora_entrega.Mes > 12);

                        do
                        {
                            cout << "Digite o Ano de entrega do veiculo: ";
                            cin >> novosDadosLocacao.Data_hora_entrega.Ano;
                            locacao.Data_hora_entrega.Ano = novosDadosLocacao.Data_hora_entrega.Ano;

                        } while (novosDadosLocacao.Data_hora_entrega.Ano < 1900 || novosDadosLocacao.Data_hora_entrega.Ano > 3000);

                        do
                        {
                            cout << "Digite a Hora/minuto de entrega do veiculo(ex: 10.30 ou 18.15): ";
                            cin >> novosDadosLocacao.Data_hora_entrega.hora;
                            locacao.Data_hora_entrega.hora = novosDadosLocacao.Data_hora_entrega.hora;

                        } while (novosDadosLocacao.Data_hora_entrega.hora <= 0 || novosDadosLocacao.Data_hora_entrega.hora > 24);

                        cout << endl
                             << endl;
                        cout << " -- Alteração  realizada com sucesso ! --" << endl
                             << endl;
                    }
                }
            }
            else
            {
                system("clear");
                cout << endl;
                cout << endl;
                cout << "---- Alerta ! ---" << endl;
                cout << "Não existe um cliente com CPF Informado" << endl;
                cout << "Informe com CPF valido !" << endl
                     << endl;
            }
        } while (verificaCPF(listaDeClientes, cpfDeBusca) != 1);
    }

    void listarLocacoes(vector<Locacao> &ListaLocacoes)
    {
        system("clear");

        if (ListaLocacoes.size() <= 0)
        {
            cout << endl
                 << endl
                 << "-- Não há nenhuma locação no Registro " << endl
                 << endl;
        }
        else
        {
            cout << "-- Registro de locações" << endl
                 << endl;
            for (auto &locacao : ListaLocacoes)
            {
                cout << "Loção Realizada ( n-Não s-Sim): " << locacao.realizada << endl;
                cout << "Veiculo placa: " << locacao.veiculo_placa << endl;
                cout << "Cliente CNH: " << locacao.cliente_cnh << endl;
                cout << "Data da Retirada: " << locacao.Data_hora_retirada.Dia << "/" << locacao.Data_hora_retirada.Mes << "/" << locacao.Data_hora_retirada.Ano << endl;
                cout << "Data da Entrega: " << locacao.Data_hora_entrega.Dia << "/" << locacao.Data_hora_entrega.Mes << "/" << locacao.Data_hora_entrega.Ano << endl;

                cout << "---------------- " << endl;
            }
        }
    }

    int menu_locacao(void)
    {
        int escolha;
        do
        {
            cout << "--- Gestão de Locação --- " << endl;
            cout << endl;

            cout << "1 - p/ Incluir Locação" << endl;
            cout << "2 - p/ Excluir um Locação" << endl;
            cout << "3 - p/ Alterar um Locação" << endl;
            cout << "4 - p/ Listar Locações" << endl;
            cout << "0 - p/ Sair " << endl;
            cout << "Sua escolha: ";
            cin >> escolha;
            cin.ignore();

        } while (escolha < 0 || escolha > 5);

        return escolha;
    }
};

struct Ocorrencia
{
    string cliente_cpf;
    string veiculo_placa;
    DataHora data;
    string apolice;
    string descricao;

    int verificaCPF_Placa_Em_Locacao(vector<Locacao> &listaDeLocacoes, string placa, string cpf)
    {
        int placaOk = 0, cpfOk = 0;

        for (auto &locacao : listaDeLocacoes)
        {
            if (locacao.veiculo_placa == placa)
            {
                placaOk = 1;
                if (locacao.cliente_cpf == cpf)
                {
                    cpfOk = 1;
                    return 1;
                }
            }
        };
        if (placaOk == 0)
        {
            cout << endl
                 << endl
                 << "-- Não existe Ocorrencia com esta placa !" << endl;
        }
        if (cpfOk == 0)
        {
            cout << endl
                 << endl
                 << "-- Não existe Ocorrencia para este CPF!" << endl;
        }
        return 0;
    }

    int menu_ocorrencia()
    {
        int escolha;
        do
        {
            cout << "--- Gestão de Ocorrência --- " << endl;
            cout << endl;

            cout << "1 - p/ Incluir Ocorrência" << endl;
            cout << "2 - p/ Excluir um Ocorrência" << endl;
            cout << "3 - p/ Alterar um Ocorrência" << endl;
            cout << "4 - p/ Listar Ocorrência por Cliente" << endl;
            cout << "5 - p/ Listar Ocorrência por Veiculo" << endl;
            cout << "0 - p/ Sair " << endl;
            cout << "Sua escolha: ";
            cin >> escolha;
            cin.ignore();

        } while (escolha < 0 || escolha > 5);

        return escolha;
    }

    void incluir_ocorrencia(Ocorrencia *ocorencia, vector<Locacao> &listaDeLocacoes)
    {

        do
        {
            cout << "Informe o CPF cliente da ocorrencia: ";
            getline(cin, ocorencia->cliente_cpf);
            cout << "Informe Placa do veiculo da ocorrencia: ";
            getline(cin, ocorencia->veiculo_placa);

            if (verificaCPF_Placa_Em_Locacao(listaDeLocacoes, ocorencia->veiculo_placa, ocorencia->cliente_cpf) != 1)
            {
                cout << endl
                     << "Tente novamente" << endl;
            }
        } while (verificaCPF_Placa_Em_Locacao(listaDeLocacoes, ocorencia->veiculo_placa, ocorencia->cliente_cpf) != 1);

        cout << "informe a police: ";
        getline(cin, ocorencia->apolice);
        cout << "informe a descricao da ocorrencia: ";
        getline(cin, ocorencia->descricao);

        do
        {
            cout << "Digite o Dia da ocorencia: ";
            cin >> ocorencia->data.Dia;
        } while (ocorencia->data.Dia <= 0 || ocorencia->data.Dia > 31);

        do
        {
            cout << "Digite o Mes da ocorencia:: ";
            cin >> ocorencia->data.Mes;
        } while (ocorencia->data.Mes <= 0 || ocorencia->data.Mes > 12);

        do
        {
            cout << "Digite o Ano da ocorencia:: ";
            cin >> ocorencia->data.Ano;
        } while (ocorencia->data.Ano < 1900 || ocorencia->data.Ano > 3000);

        do
        {
            cout << "Digite a Hora/minuto da ocorencia:(ex: 10.30 ou 18.15): ";
            cin >> ocorencia->data.hora;
        } while (ocorencia->data.hora <= 0 || ocorencia->data.hora > 24);

        cout << endl
             << endl;
        cout << " -- Ocorrencia realizada com sucesso ! --" << endl
             << endl;
    }

    void excluir_ocorrencia(vector<Ocorrencia> &listaDeOcorrencia)
    {
        string cpfDeBusca, placaDeBusca;
        int valificacao = 0, placaOk = 0, cpfOk = 0, cont = -1;

        do
        {
            cout << "Informe o CPF cliente da ocorrencia: ";
            getline(cin, cpfDeBusca);
            cout << "Informe Placa do veiculo da ocorrencia: ";
            getline(cin, placaDeBusca);

            vector<Ocorrencia>::iterator i;
            i = listaDeOcorrencia.begin();
            for (auto &ocorrencia : listaDeOcorrencia)
            {
                cont += 1;
                if (ocorrencia.veiculo_placa == placaDeBusca)
                {
                    placaOk = 1;
                    if (ocorrencia.cliente_cpf == cpfDeBusca)
                    {
                        cpfOk = 1;

                        advance(i, cont);
                        listaDeOcorrencia.erase(i);
                        cout << "Ocorrencia Excluída com Sucesso !" << endl;
                        valificacao = 1;
                    }
                }
            };
            if (placaOk == 0)
            {
                cout << endl
                     << endl
                     << "-- Não existe locacão com esta placa !" << endl;
            }
            if (cpfOk == 0)
            {
                cout << endl
                     << endl
                     << "-- Não existe locacão para este CPF!" << endl;
            }

        } while (valificacao != 1);
    }
    void alterar_ocorrencia(vector<Ocorrencia> &listaDeOcorrencia)
    {
        Ocorrencia novosDados;
        string cpfDeBusca, placaDeBusca;
        int valificacao = 0, placaOk = 0, cpfOk = 0, opcao;

        do
        {
            cout << "Informe o CPF cliente da ocorrencia: ";
            getline(cin, cpfDeBusca);
            cout << "Informe Placa do veiculo da ocorrencia: ";
            getline(cin, placaDeBusca);

            for (auto &ocorrencia : listaDeOcorrencia)
            {
                if (ocorrencia.veiculo_placa == placaDeBusca)
                {
                    if (ocorrencia.cliente_cpf == cpfDeBusca)
                    {
                        cpfOk = 1;
                        valificacao = 1;

                        cout << endl
                             << "Descrição da ocorrencia: " << ocorrencia.descricao << endl;

                        cout << "Deseja alterar os dados da ocorrencia 1 - Sim | 2 - Não : ";
                        cin >> opcao;
                        cin.ignore();

                        if (opcao == 1)
                        {
                            cout << "informe a  nova police: ";
                            getline(cin, ocorrencia.apolice);

                            cout << "informe a nova descricao da ocorrencia: ";
                            getline(cin, ocorrencia.descricao);

                            do
                            {
                                cout << "Digite o novo Dia da ocorencia: ";
                                cin >> ocorrencia.data.Dia;
                            } while (ocorrencia.data.Dia <= 0 || ocorrencia.data.Dia > 31);

                            do
                            {
                                cout << "Digite o novo Mes da ocorencia:: ";
                                cin >> ocorrencia.data.Mes;
                            } while (ocorrencia.data.Mes <= 0 || ocorrencia.data.Mes > 12);

                            do
                            {
                                cout << "Digite o novo Ano da ocorencia:: ";
                                cin >> ocorrencia.data.Ano;
                            } while (ocorrencia.data.Ano < 1900 || ocorrencia.data.Ano > 3000);

                            do
                            {
                                cout << "Digite a nova Hora/minuto da ocorencia:(ex: 10.30 ou 18.15): ";
                                cin >> ocorrencia.data.hora;
                            } while (ocorrencia.data.hora <= 0 || ocorrencia.data.hora > 24);

                            cout << endl
                                 << endl;
                            cout << " -- Alteracao de Ocorrencia realizada com sucesso ! --" << endl
                                 << endl;
                        }

                    }else{
                        return;
                    }
                }
            };
            if (placaOk == 0)
            {
                cout << endl
                     << endl
                     << "-- Não existe locacão com esta placa !" << endl;
            }
            if (cpfOk == 0)
            {
                cout << endl
                     << endl
                     << "-- Não existe locacão para este CPF!" << endl;
            }

        } while (valificacao != 1);
    }
    void lista_ocorrencia_cliente(vector<Ocorrencia> listaDeOcorrencia)
    {
        string cpfdeBusca;
        int validacao = 0, sair = 0;

        do
        {
            cout << "Informe o CPF do cliente da ocorrencia: ";
            getline(cin, cpfdeBusca);

            cout << endl
                 << endl
                 << "--Ocorrencias por CPF do  Cliente--" << endl
                 << endl;

            for (auto &ocorrencia : listaDeOcorrencia)
            {
                if (ocorrencia.cliente_cpf == cpfdeBusca)
                {
                    validacao = 1;
                    cout << "CPF cliente da ocorrencia: " << ocorrencia.cliente_cpf << endl;
                    cout << "Placa do veiculo da ocorrencia: " << ocorrencia.veiculo_placa << endl;
                    cout << "Apolice: " << ocorrencia.apolice << endl;
                    cout << "Descricao da ocorrencia: " << ocorrencia.descricao << endl;
                    cout << "Data da ocorrencia: " << ocorrencia.data.Dia << "/" << ocorrencia.data.Mes << "/" << ocorrencia.data.Ano << endl;
                }
            }
            if (validacao == 0)
            {
                cout << "--- ALERTA ---" << endl;
                cout << "Não há ocorrencias com o CPF informado, verifique o CPF e tente novamente" << endl
                     << endl;
                return;
            }

        } while (validacao != 1);
    }
    void lista_ocorrencia_veiculo(vector<Ocorrencia> listaDeOcorrencia)
    {

        string placadeBusca;
        int validacao = 0;

        do
        {
            cout << endl
                 << "Informe placa do veiculo da ocorrencia: ";
            getline(cin, placadeBusca);

            cout << endl
                 << endl
                 << "-- Ocorrencias por Placa do viculo --" << endl
                 << endl;

            for (auto &ocorrencia : listaDeOcorrencia)
            {
                if (ocorrencia.cliente_cpf == placadeBusca)
                {
                    validacao = 1;
                    cout << "CPF cliente da ocorrencia: " << ocorrencia.cliente_cpf << endl;
                    cout << "Placa do veiculo da ocorrencia: " << ocorrencia.veiculo_placa << endl;
                    cout << "Apolice: " << ocorrencia.apolice << endl;
                    cout << "Descricao da ocorrencia: " << ocorrencia.descricao << endl;
                    cout << "Data da ocorrencia: " << ocorrencia.data.Dia << "/" << ocorrencia.data.Mes << "/" << ocorrencia.data.Ano << endl;
                }
            }
            if (validacao == 0)
            {
                cout << "--- ALERTA ---" << endl;
                cout << "Não há ocorrencias com a placa informada, verifique a placa e tente novamente" << endl
                     << endl;
                return;
            }

        } while (validacao != 1);
    }
};
int main(void)
{
    Cliente clienteDados;
    Veiculo veiculoDados;
    Locacao locacaoDados;
    Ocorrencia ocorrenciaDados;

    vector<Cliente> listaDeClientes;
    vector<Veiculo> listaDeVeiculos;
    vector<Locacao> listaDeLocacoes;
    vector<Ocorrencia> listaDeOcorrencia;

    int opcaoDeMenu, opcaoDeServico;

    do
    {
        system("clear");
        cout << " 1 - P/ Gestão de Clientes" << endl;
        cout << " 2 - P/ Gestão de Veiculos" << endl;
        cout << " 3 - P/ Gestão de Locação" << endl;
        cout << " 4 - P/ Gestão de Ocorrências" << endl;
        cout << " 0 - P/ Finalizar Programa" << endl;
        cout << " Sua opcao: ";
        cin >> opcaoDeMenu;

        if (opcaoDeMenu == 1)
        {
            do
            {
                opcaoDeServico = clienteDados.menu_cliente();

                switch (opcaoDeServico)
                {
                case 1:
                    clienteDados.incluirCliente(&clienteDados);
                    listaDeClientes.push_back(clienteDados);
                    break;
                case 2:
                    clienteDados.excluirCliente(listaDeClientes);
                    break;

                case 3:
                    clienteDados.alterarCliente(listaDeClientes);
                    break;
                case 4:
                    clienteDados.listarClientes(listaDeClientes);
                    break;
                case 5:
                    clienteDados.localizaCliente(listaDeClientes);
                    break;

                default:
                    break;
                }
            } while (opcaoDeServico != 0);
        }
        else if (opcaoDeMenu == 2)
        {
            do
            {
                opcaoDeServico = veiculoDados.menu_veiculo();

                switch (opcaoDeServico)
                {
                case 1:
                    veiculoDados.incluirVeiculo(&veiculoDados);
                    listaDeVeiculos.push_back(veiculoDados);
                    break;
                case 2:
                    veiculoDados.excluirVeiculo(listaDeVeiculos);
                    break;

                case 3:
                    veiculoDados.alterarVeiculo(listaDeVeiculos);
                    break;
                case 4:
                    veiculoDados.listarVeiculos(listaDeVeiculos);
                    break;
                case 5:
                    veiculoDados.localizaVeiculo(listaDeVeiculos);
                    break;

                default:
                    break;
                }
            } while (opcaoDeServico != 0);
        }
        else if (opcaoDeMenu == 3)
        {

            do
            {
                opcaoDeServico = locacaoDados.menu_locacao();

                switch (opcaoDeServico)
                {
                case 1:
                    locacaoDados.incluirLocacao(&locacaoDados, listaDeClientes, listaDeVeiculos);
                    listaDeLocacoes.push_back(locacaoDados);
                    break;
                case 2:
                    locacaoDados.excluirLocacao(listaDeLocacoes);

                    break;

                case 3:
                    locacaoDados.alterarLocacao(listaDeLocacoes, listaDeClientes);
                    break;
                case 4:
                    locacaoDados.listarLocacoes(listaDeLocacoes);
                    break;
                default:
                    break;
                }
            } while (opcaoDeServico != 0);
        }
        else if (opcaoDeMenu == 4)
        {
            do
            {
                opcaoDeServico = ocorrenciaDados.menu_ocorrencia();

                switch (opcaoDeServico)
                {
                case 1:
                    ocorrenciaDados.incluir_ocorrencia(&ocorrenciaDados, listaDeLocacoes);
                    listaDeOcorrencia.push_back(ocorrenciaDados);
                    break;
                case 2:
                    ocorrenciaDados.excluir_ocorrencia(listaDeOcorrencia);
                    break;
                case 3:
                    ocorrenciaDados.alterar_ocorrencia(listaDeOcorrencia);
                    break;
                case 4:
                    ocorrenciaDados.lista_ocorrencia_cliente(listaDeOcorrencia);
                    break;
                case 5:
                    ocorrenciaDados.lista_ocorrencia_veiculo(listaDeOcorrencia);
                    break;

                default:
                    break;
                }
            } while (opcaoDeServico != 0);
        }
    } while (opcaoDeMenu != 0);
    return 0;
}