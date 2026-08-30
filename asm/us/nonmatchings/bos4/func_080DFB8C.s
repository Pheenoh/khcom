.syntax unified
	.align 2, 0
	.global func_080DFB8C
	.thumb
	.thumb_func
	.type func_080DFB8C, %function
func_080DFB8C: @ 080DFB8C
	push {lr}
	cmp r0, #0x00
	bge _080DFB96
	ldr r2, _080DFBC0 @ =0x00001FFF
	adds r0, r0, r2
_080DFB96:
	lsls r0, r0, #0x03
	lsrs r2, r0, #0x10
	cmp r1, #0x00
	bge _080DFBA2
	ldr r0, _080DFBC4 @ =0x00000FFF
	adds r1, r1, r0
_080DFBA2:
	lsls r0, r1, #0x04
	lsrs r1, r0, #0x10
	ldr r0, _080DFBC8 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	blt _080DFBCC
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E548C
	b _080DFBD8
	.byte 0x00, 0x00
_080DFBC0: .4byte 0x00001FFF
_080DFBC4: .4byte 0x00000FFF
_080DFBC8: .4byte 0x0203C7AC
_080DFBCC:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E58F8
_080DFBD8:
	pop {r1}
	bx r1
.syntax divided
