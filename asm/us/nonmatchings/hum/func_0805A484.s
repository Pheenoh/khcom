.syntax unified
	.align 2, 0
	.global func_0805A484
	.thumb
	.thumb_func
	.type func_0805A484, %function
func_0805A484: @ 0805A484
	push {r4, r5, r6, r7, lr}
	movs r5, #0x00
	ldr r6, _0805A4D0 @ =0x02034934
	movs r7, #0x00
_0805A48C:
	ldr r0, [r6, #0x00]
	ldr r1, _0805A4D4 @ =0x00000C68
	adds r0, r0, r1
	adds r0, r0, r5
	strb r7, [r0, #0x00]
	lsls r4, r5, #0x01
	adds r4, r4, r5
	lsls r4, r4, #0x07
	adds r1, r4, #0x0
	adds r1, #0x60
	ldr r0, [r6, #0x00]
	adds r0, r0, r1
	movs r1, #0x30
	bl func_08065AE0
	adds r3, r5, #0x1
	movs r2, #0x2F
_0805A4AE:
	ldr r0, [r6, #0x00]
	adds r0, #0x60
	adds r1, r0, r4
	ldr r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0805A4BC
	str r7, [r1, #0x00]
_0805A4BC:
	adds r4, #0x08
	subs r2, #0x01
	cmp r2, #0x00
	bge _0805A4AE
	adds r5, r3, #0x0
	cmp r5, #0x07
	ble _0805A48C
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0805A4D0: .4byte 0x02034934
_0805A4D4: .4byte 0x00000C68
.syntax divided
