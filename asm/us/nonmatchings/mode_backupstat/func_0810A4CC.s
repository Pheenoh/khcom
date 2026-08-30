.syntax unified
	.align 2, 0
	.global func_0810A4CC
	.thumb
	.thumb_func
	.type func_0810A4CC, %function
func_0810A4CC: @ 0810A4CC
	push {r4, r5, r6, lr}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r5, [sp, #0x024]
	ldr r4, [sp, #0x028]
	lsls r1, r1, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r0, sp
	strb r4, [r0, #0x00]
	lsrs r1, r1, #0x08
	strh r1, [r0, #0x02]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	str r5, [sp, #0x00C]
	movs r1, #0xBA
	lsls r1, r1, #0x02
	adds r0, r6, r1
	str r0, [sp, #0x010]
	ldr r0, _0810A514 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x2C
	ldr r1, _0810A518 @ =0x09EF9E24
	mov r2, sp
	bl func_08000E14
	lsls r4, r4, #0x02
	movs r2, #0xB5
	lsls r2, r2, #0x02
	adds r1, r6, r2
	adds r1, r1, r4
	str r0, [r1, #0x00]
	add sp, #0x014
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_0810A514: .4byte 0x02039B84
_0810A518: .4byte 0x09EF9E24
.syntax divided
