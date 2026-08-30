.syntax unified
	.align 2, 0
	.global mode_allmap_2
	.thumb
	.thumb_func
	.type mode_allmap_2, %function
mode_allmap_2: @ 080D34AC
	push {lr}
	bl func_080D53A8
	ldr r0, _080D3504 @ =0x0203C4F0
	bl func_08000F0C
	ldr r3, _080D3508 @ =0x04000208
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r2, _080D350C @ =0x04000200
	ldrh r1, [r2, #0x00]
	ldr r0, _080D3510 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2, #0x00]
	ldr r2, _080D3514 @ =0x04000004
	ldrh r1, [r2, #0x00]
	ldr r0, _080D3518 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2, #0x00]
	movs r0, #0x01
	strh r0, [r3, #0x00]
	bl func_08006C68
	ldr r0, _080D351C @ =0x02034E81
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D34EE
	ldr r0, _080D3520 @ =0x0203DB10
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r1, #0xFF
	bl func_08120EF8
_080D34EE:
	ldr r0, _080D3524 @ =0x0203C530
	ldr r0, [r0, #0x00]
	bl func_080009C4
	ldr r0, _080D3528 @ =0x0203C504
	ldr r0, [r0, #0x00]
	bl func_080009C4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3504: .4byte 0x0203C4F0
_080D3508: .4byte 0x04000208
_080D350C: .4byte 0x04000200
_080D3510: .4byte 0x0000FFFB
_080D3514: .4byte 0x04000004
_080D3518: .4byte 0x0000FFDF
_080D351C: .4byte 0x02034E81
_080D3520: .4byte 0x0203DB10
_080D3524: .4byte 0x0203C530
_080D3528: .4byte 0x0203C504
	.byte 0x01, 0x49, 0x08, 0x70, 0x70, 0x47, 0x00, 0x00, 0x80, 0x4E, 0x03, 0x02
.syntax divided
