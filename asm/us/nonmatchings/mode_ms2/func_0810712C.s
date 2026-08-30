.syntax unified
	.align 2, 0
	.global func_0810712C
	.thumb
	.thumb_func
	.type func_0810712C, %function
func_0810712C: @ 0810712C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _08107144
	ldr r1, _08107140 @ =0x02035E30
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	b _08107146
	.byte 0x00, 0x00
_08107140: .4byte 0x02035E30
_08107144:
	movs r0, #0x00
_08107146:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bx lr
.syntax divided
