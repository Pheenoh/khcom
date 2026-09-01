.syntax unified
	.align 2, 0
	.global func_08001DB0
	.thumb
	.thumb_func
	.type func_08001DB0, %function
func_08001DB0: @ 08001DB0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	orrs r1, r0
	ldr r0, _08001DE0 @ =0xC000C000
	ands r1, r0
	ldr r0, _08001DE4 @ =0x40008000
	cmp r1, r0
	beq _08001E54
	cmp r1, r0
	bhi _08001DFC
	movs r0, #0x80
	lsls r0, r0, #0x08
	cmp r1, r0
	beq _08001E50
	cmp r1, r0
	bhi _08001DE8
	cmp r1, #0x00
	beq _08001E44
	movs r0, #0x80
	lsls r0, r0, #0x07
	cmp r1, r0
	beq _08001E50
	b _08001E60
_08001DE0: .4byte 0xC000C000
_08001DE4: .4byte 0x40008000
_08001DE8:
	movs r0, #0x80
	lsls r0, r0, #0x17
	cmp r1, r0
	beq _08001E54
	ldr r0, _08001DF8 @ =0x40004000
	cmp r1, r0
	beq _08001E54
	b _08001E60
_08001DF8: .4byte 0x40004000
_08001DFC:
	ldr r0, _08001E18 @ =0x80008000
	cmp r1, r0
	beq _08001E58
	cmp r1, r0
	bhi _08001E20
	movs r0, #0x80
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08001E48
	ldr r0, _08001E1C @ =0x80004000
	cmp r1, r0
	beq _08001E58
	b _08001E60
	.byte 0x00, 0x00
_08001E18: .4byte 0x80008000
_08001E1C: .4byte 0x80004000
_08001E20:
	ldr r0, _08001E34 @ =0xC0004000
	cmp r1, r0
	beq _08001E5C
	cmp r1, r0
	bhi _08001E38
	movs r0, #0xC0
	lsls r0, r0, #0x18
	cmp r1, r0
	beq _08001E4C
	b _08001E60
_08001E34: .4byte 0xC0004000
_08001E38:
	ldr r0, _08001E40 @ =0xC0008000
	cmp r1, r0
	beq _08001E5C
	b _08001E60
_08001E40: .4byte 0xC0008000
_08001E44:
	movs r0, #0x01
	b _08001E62
_08001E48:
	movs r0, #0x10
	b _08001E62
_08001E4C:
	movs r0, #0x40
	b _08001E62
_08001E50:
	movs r0, #0x02
	b _08001E62
_08001E54:
	movs r0, #0x04
	b _08001E62
_08001E58:
	movs r0, #0x08
	b _08001E62
_08001E5C:
	movs r0, #0x20
	b _08001E62
_08001E60:
	movs r0, #0x00
_08001E62:
	bx lr
.syntax divided
