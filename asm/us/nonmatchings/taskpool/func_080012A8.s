.syntax unified
	.align 2, 0
	.global func_080012A8
	.thumb
	.thumb_func
	.type func_080012A8, %function
func_080012A8: @ 080012A8
	push {lr}
	ldr r0, _080012D4 @ =0x0300749C
	ldrb r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080012C2
	ldr r0, _080012D8 @ =0x030074A0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080012C2
	bl _call_via_r0
_080012C2:
	ldr r0, _080012DC @ =0x030074A4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080012CE
	bl _call_via_r0
_080012CE:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080012D4: .4byte 0x0300749C
_080012D8: .4byte 0x030074A0
_080012DC: .4byte 0x030074A4
.syntax divided
