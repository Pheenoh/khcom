.syntax unified
	.align 2, 0
	.global func_080D6D2C
	.thumb
	.thumb_func
	.type func_080D6D2C, %function
func_080D6D2C: @ 080D6D2C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r5, r0, #0x0
	adds r0, #0x60
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r2, _080D6DAC @ =0x09EF6668
	ldr r1, [r5, #0x44]
	movs r3, #0x00
	ldsh r1, [r1, r3]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	ldr r2, [r1, #0x00]
	ldr r3, [r5, #0x00]
	ldr r1, [r5, #0x04]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	movs r1, #0x80
	lsls r1, r1, #0x03
	str r1, [sp, #0x008]
	movs r1, #0x64
	str r1, [sp, #0x00C]
	movs r1, #0x38
	bl func_080023E0
	movs r6, #0x00
	movs r7, #0xE0
	lsls r7, r7, #0x0E
_080D6D66:
	adds r0, r5, #0x0
	adds r0, #0x60
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r4, r6, #0x02
	adds r1, r5, #0x0
	adds r1, #0x20
	adds r1, r1, r4
	ldr r2, [r1, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x08
	adds r1, r1, r4
	ldr r3, [r1, #0x00]
	adds r1, r5, #0x0
	adds r1, #0x14
	adds r1, r1, r4
	ldr r1, [r1, #0x00]
	str r1, [sp, #0x000]
	movs r1, #0x00
	str r1, [sp, #0x004]
	str r1, [sp, #0x008]
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x00C]
	asrs r1, r7, #0x10
	bl func_080023E0
	adds r6, #0x01
	cmp r6, #0x02
	ble _080D6D66
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D6DAC: .4byte 0x09EF6668
.syntax divided
