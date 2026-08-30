.syntax unified
	.align 2, 0
	.global func_0809B644
	.thumb
	.thumb_func
	.type func_0809B644, %function
func_0809B644: @ 0809B644
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r0, [sp, #0x024]
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r7, _0809B6C4 @ =0x02039DD4
	ldr r1, [r7, #0x00]
	cmp r1, #0x00
	beq _0809B6BC
	adds r0, r1, #0x0
	adds r0, #0xDA
	ldrb r0, [r0, #0x00]
	cmp r0, #0x04
	bhi _0809B6BC
	adds r0, r1, #0x0
	adds r0, #0xD6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0809B6BC
	lsls r0, r4, #0x10
	asrs r0, r0, #0x08
	str r0, [sp, #0x000]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x08
	str r0, [sp, #0x004]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x08
	str r0, [sp, #0x008]
	bl func_080065A4
	ldr r1, _0809B6C8 @ =0x09036210
	lsls r4, r5, #0x02
	adds r4, r4, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x09
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #0x00]
	adds r1, r1, r0
	str r1, [sp, #0x00C]
	ldr r1, _0809B6CC @ =0x09EE778C
	adds r0, r6, #0x0
	mov r2, sp
	bl func_08000E14
	ldr r1, [r7, #0x00]
	adds r1, #0xD6
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
_0809B6BC:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0809B6C4: .4byte 0x02039DD4
_0809B6C8: .4byte 0x09036210
_0809B6CC: .4byte 0x09EE778C
.syntax divided
