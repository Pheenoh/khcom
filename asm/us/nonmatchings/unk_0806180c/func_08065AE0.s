.syntax unified
	.align 2, 0
	.global func_08065AE0
	.thumb
	.thumb_func
	.type func_08065AE0, %function
func_08065AE0: @ 08065AE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	cmp r1, #0x00
	ble _08065B02
	movs r6, #0x00
	adds r5, r1, #0x0
_08065AEC:
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08065AF8
	bl func_080028C0
	str r6, [r4, #0x00]
_08065AF8:
	strb r6, [r4, #0x05]
	adds r4, #0x08
	subs r5, #0x01
	cmp r5, #0x00
	bne _08065AEC
_08065B02:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
