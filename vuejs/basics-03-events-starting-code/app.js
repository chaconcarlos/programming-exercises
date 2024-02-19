const app = Vue.createApp({
  data() {
    return {
      name: '',
      counter: 10,
    };
  },
  'methods': {
    add() {
      // The declaration has to be like this, and not in the anonymous form, which will not take correctly the scope for this.counter.
      this.counter = this.counter + 1;
    },
    reduce() {
      this.counter = this.counter - 1;
    },
    setName(event, name) {
      this.name = event.target.value + ' ' + name;
    },
    submitForm(event) {
      //event.preventDefault();
      alert('Submitted!');
    }
  }
});

app.mount('#events');
