.syntax unified
	.align 2, 0
	.global func_080E04EC
	.thumb
	.thumb_func
	.type func_080E04EC, %function
func_080E04EC: @ 080E04EC
	push {lr}
	ldr r0, _080E0500 @ =0x0203C590
	ldrb r1, [r0, #0x06]
	cmp r1, #0xFE
	bgt _080E0508
	cmp r1, #0xFC
	blt _080E0508
	ldr r0, _080E0504 @ =0x09EF6AC0
	b _080E0510
	.byte 0x00, 0x00
_080E0500: .4byte 0x0203C590
_080E0504: .4byte 0x09EF6AC0
_080E0508:
	ldrb r0, [r0, #0x04]
	cmp r0, #0x0D
	beq _080E051C
	ldr r0, _080E0518 @ =0x09EF6AA0
_080E0510:
	movs r1, #0x00
	bl func_080010CC
	b _080E0524
_080E0518: .4byte 0x09EF6AA0
_080E051C:
	ldr r0, _080E0528 @ =0x09EF3C88
	movs r1, #0x01
	bl func_080010CC
_080E0524:
	pop {r0}
	bx r0
_080E0528: .4byte 0x09EF3C88
.syntax divided
