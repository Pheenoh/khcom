.syntax unified
	.align 2, 0
	.global func_08034518
	.thumb
	.thumb_func
	.type func_08034518, %function
func_08034518: @ 08034518
	push {r4, r5, r6, r7, lr}
	add sp, #-0x020
	adds r7, r0, #0x0
	mov r1, sp
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	add r4, sp, #0x010
	adds r1, r4, #0x0
	adds r0, r7, #0x0
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	ldr r0, [sp, #0x004]
	ldr r5, _08034584 @ =0xFFFFFA00
	adds r0, r0, r5
	str r0, [sp, #0x004]
	ldr r0, [r4, #0x04]
	movs r1, #0xC0
	lsls r1, r1, #0x03
	adds r0, r0, r1
	str r0, [r4, #0x04]
	mov r0, sp
	bl func_080DFF1C
	adds r6, r0, #0x0
	ldr r0, [sp, #0x00C]
	cmp r6, r0
	ble _08034558
	str r6, [sp, #0x00C]
_08034558:
	adds r0, r4, #0x0
	bl func_080DFF1C
	adds r5, r0, #0x0
	ldr r0, [r4, #0x0C]
	cmp r5, r0
	ble _08034568
	str r5, [r4, #0x0C]
_08034568:
	mov r0, sp
	bl func_080DFBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08034580
	adds r0, r4, #0x0
	bl func_080DFBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08034588
_08034580:
	movs r0, #0x01
	b _08034594
_08034584: .4byte 0xFFFFFA00
_08034588:
	adds r0, r5, #0x0
	cmp r0, r6
	ble _08034590
	adds r0, r6, #0x0
_08034590:
	str r0, [r7, #0x0C]
	movs r0, #0x00
_08034594:
	add sp, #0x020
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
