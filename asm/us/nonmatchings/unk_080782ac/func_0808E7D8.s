.syntax unified
	.align 2, 0
	.global func_0808E7D8
	.thumb
	.thumb_func
	.type func_0808E7D8, %function
func_0808E7D8: @ 0808E7D8
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	mov r9, r0
	movs r0, #0xFE
	lsls r0, r0, #0x03
	add r0, r9
	bl func_08000C8C
	adds r4, r0, #0x0
	movs r6, #0x00
	mov r8, r6
	cmp r4, #0x00
	beq _0808E866
	movs r7, #0x00
_0808E7F8:
	strh r6, [r4, #0x22]
	mov r0, r8
	strh r0, [r4, #0x24]
	lsls r0, r6, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x09
	adds r0, r0, r1
	lsrs r6, r0, #0x10
	adds r5, r4, #0x0
	adds r5, #0x48
	ldrh r1, [r5, #0x00]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0808E840
	ldr r0, [r4, #0x04]
	bl func_08002C10
	ldr r0, [r4, #0x08]
	bl func_080028C0
	ldr r0, [r4, #0x0C]
	bl func_08002C10
	ldr r0, [r4, #0x10]
	bl func_080028C0
	ldrh r0, [r5, #0x00]
	ldr r2, _0808E884 @ =0x0000FFFE
	adds r1, r2, #0x0
	ands r0, r1
	strh r0, [r5, #0x00]
	str r7, [r4, #0x08]
	str r7, [r4, #0x0C]
	str r7, [r4, #0x10]
	str r7, [r4, #0x04]
_0808E840:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x02
	ble _0808E858
	movs r6, #0x00
	mov r1, r8
	lsls r0, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	mov r8, r0
_0808E858:
	adds r0, r4, #0x0
	adds r0, #0x2C
	bl func_08000CD4
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0808E7F8
_0808E866:
	ldr r1, _0808E888 @ =0x00000854
	add r1, r9
	movs r0, #0xA0
	lsls r0, r0, #0x06
	str r0, [r1, #0x00]
	ldr r1, _0808E88C @ =0x000008AC
	add r1, r9
	movs r0, #0x04
	strh r0, [r1, #0x00]
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0808E884: .4byte 0x0000FFFE
_0808E888: .4byte 0x00000854
_0808E88C: .4byte 0x000008AC
.syntax divided
