.syntax unified
	.align 2, 0
	.global func_080DB04C
	.thumb
	.thumb_func
	.type func_080DB04C, %function
func_080DB04C: @ 080DB04C
	push {r4, lr}
	add sp, #-0x00C
	adds r2, r0, #0x0
	adds r4, r2, #0x0
	adds r4, #0x2C
	ldr r0, _080DB078 @ =0x0203C578
	ldrb r3, [r0, #0x00]
	cmp r3, #0x00
	beq _080DB07C
	movs r0, #0xA4
	lsls r0, r0, #0x01
	adds r1, r2, r0
	subs r0, #0x48
	str r0, [r1, #0x00]
	adds r0, #0x4C
	adds r1, r2, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x06
	b _080DB090
	.byte 0x00, 0x00
_080DB078: .4byte 0x0203C578
_080DB07C:
	movs r1, #0xA4
	lsls r1, r1, #0x01
	adds r0, r2, r1
	ldr r1, _080DB0C8 @ =0xFFFFFF00
	str r1, [r0, #0x00]
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r2, r1
	str r3, [r0, #0x00]
	ldr r2, _080DB0CC @ =0xFFFFE000
_080DB090:
	movs r0, #0x83
	lsls r0, r0, #0x01
	ldr r1, [r4, #0x04]
	subs r1, r1, r2
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	ldr r4, _080DB0D0 @ =0xFFFFF000
	adds r3, r3, r4
	movs r4, #0x04
	str r4, [sp, #0x000]
	movs r4, #0x1C
	str r4, [sp, #0x004]
	movs r4, #0x10
	str r4, [sp, #0x008]
	bl func_08011F78
	adds r1, r0, #0x0
	cmp r1, #0x01
	bne _080DB0C0
	ldr r0, _080DB0D4 @ =0x0203C56C
	strb r1, [r0, #0x00]
	ldr r0, _080DB0D8 @ =0x00000226
	bl m4aSongNumStart
_080DB0C0:
	add sp, #0x00C
	pop {r4}
	pop {r0}
	bx r0
_080DB0C8: .4byte 0xFFFFFF00
_080DB0CC: .4byte 0xFFFFE000
_080DB0D0: .4byte 0xFFFFF000
_080DB0D4: .4byte 0x0203C56C
_080DB0D8: .4byte 0x00000226
.syntax divided
