.syntax unified
	.align 2, 0
	.global func_080C7F94
	.thumb
	.thumb_func
	.type func_080C7F94, %function
func_080C7F94: @ 080C7F94
	push {r4, lr}
	add sp, #-0x040
	adds r4, r0, #0x0
	ldr r1, _080C7FD8 @ =0x096FC01C
	mov r0, sp
	movs r2, #0x40
	bl _0811F030
	adds r0, r4, #0x0
	adds r0, #0x38
	ldrb r1, [r0, #0x00]
	adds r1, #0x10
	movs r2, #0xFF
	ands r1, r2
	lsrs r1, r1, #0x05
	adds r0, #0x02
	ldrb r0, [r0, #0x00]
	adds r0, #0x10
	ands r0, r2
	lsrs r0, r0, #0x05
	lsls r1, r1, #0x03
	adds r0, r0, r1
	add r0, sp
	ldrb r1, [r0, #0x00]
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x03
	beq _080C7FDC
	adds r0, r1, #0x2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080C7FE2
	.byte 0x00, 0x00
_080C7FD8: .4byte 0x096FC01C
_080C7FDC:
	adds r0, r4, #0x0
	adds r0, #0x3B
	ldrb r0, [r0, #0x00]
_080C7FE2:
	add sp, #0x040
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
