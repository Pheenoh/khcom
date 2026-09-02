.syntax unified
	.align 2, 0
	.global func_080A1B4C
	.thumb
	.thumb_func
	.type func_080A1B4C, %function
func_080A1B4C: @ 080A1B4C
	push {r4, r5, r6, lr}
	add sp, #-0x018
	adds r2, r0, #0x0
	adds r3, r1, #0x0
	ldr r1, _080A1B98 @ =0x02034AF8
	movs r0, #0x00
	strb r0, [r1, #0x00]
	ldr r6, _080A1B9C @ =0x02039B84
	ldr r0, [r6, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	ldr r4, _080A1BA0 @ =0x00020000
	ldr r5, _080A1BA4 @ =0x00000000
	ands r0, r4
	movs r1, #0x00
	orrs r1, r0
	cmp r1, #0x00
	bne _080A1BAC
	ldr r0, [r2, #0x04]
	str r0, [sp, #0x000]
	ldr r0, [r2, #0x08]
	str r0, [sp, #0x004]
	mov r0, sp
	strb r1, [r0, #0x08]
	str r2, [sp, #0x00C]
	ldr r1, _080A1BA8 @ =0x09EE7950
	adds r0, r3, #0x0
	mov r2, sp
	bl TaskCreate
	ldr r2, [r6, #0x00]
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6C]
	orrs r0, r4
	str r0, [r2, #0x68]
	str r1, [r2, #0x6C]
	movs r0, #0x01
	b _080A1BAE
_080A1B98: .4byte 0x02034AF8
_080A1B9C: .4byte 0x02039B84
_080A1BA0: .4byte 0x00020000
_080A1BA4: .4byte 0x00000000
_080A1BA8: .4byte 0x09EE7950
_080A1BAC:
	movs r0, #0x00
_080A1BAE:
	add sp, #0x018
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
