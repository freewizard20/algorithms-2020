function endZeros(value: number): number {
    const s = String(value);
    return s.length - s.replace(/0*$/, '').length;
}



console.log('Example:');
console.log(endZeros(0));
