.syntax unified
	.align 2, 0
	.global func_080DEC00
	.thumb
	.thumb_func
	.type func_080DEC00, %function
func_080DEC00: @ 080DEC00
	ldr r2, _080DEC20 @ =0x02039BB0
	ldr r0, [r2, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080DEC2E
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	cmp r0, #0x05
	beq _080DEC36
	cmp r0, #0x05
	bgt _080DEC24
	cmp r0, #0x01
	beq _080DEC36
	b _080DEC3C
	.byte 0x00, 0x00
_080DEC20: .4byte 0x02039BB0
_080DEC24:
	cmp r0, #0x0B
	bgt _080DEC3C
	cmp r0, #0x08
	blt _080DEC3C
	b _080DEC36
_080DEC2E:
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	cmp r0, #0x0C
	beq _080DEC3C
_080DEC36:
	ldr r1, _080DEC40 @ =0x0203C590
	movs r0, #0x05
	strb r0, [r1, #0x07]
_080DEC3C:
	bx lr
	.byte 0x00, 0x00
_080DEC40: .4byte 0x0203C590
_080DEC44:
.syntax divided
